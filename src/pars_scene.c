/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:31:22 by student           #+#    #+#             */
/*   Updated: 2020/07/09 13:35:49 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		free_split(char **split)
{
	int		i;

	i = -1;
	while (split[++i] != NULL)
		free(split[i]);
	free(split);
}

static int		add_light(t_rtv1 *rtv, t_light *lt)
{
	if (!lt)
		return (0);
	rtv->light[rtv->lt_count] = lt;
	rtv->lt_count++;
	return (1);
}

static int		add_obj(t_rtv1 *rtv, t_obj *obj)
{
	if (!obj)
		return (0);
	rtv->obj[rtv->obj_count] = obj;
	rtv->obj_count++;
	return (1);
}

static t_light	*get_light(char **split)
{
	t_light	*light;
	double	bright;
	int		tab[4];
	int		i;
	int		type;

	i = -1;
	if (!ft_strncmp(split[1], "POINT", 5))
		type = POINT;
	else if (!ft_strncmp(split[1], "DIR", 3))
		type = DIR;
	else if (!ft_strncmp(split[1], "AMB", 3))
		type = AMB;
	else
		return (NULL);
	split += 2;
	if (split_len(split) != 4)
		return (NULL);
	while (split[++i])
		tab[i] = ft_atoi(split[i]);
	bright = (double)tab[3] / 100;
	light = ft_newlight(ft_newdot(tab[0], tab[1], tab[2]), type, bright);
	return (light);
}

int				pars_stract(t_rtv1 *rtv, char *file)
{
	char	**split;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(split = ft_strsplit(line, ' ')))
			return (0);
		if (!ft_strncmp(split[0], "camera", 6))
			rtv->o = ft_newdot(ft_atoi(split[1]) + WIDTH / 2,
					ft_atoi(split[2]) + HEIGHT / 2, ft_atoi(split[3]));
		if (!ft_strncmp(split[0], "light:", 6))
			if (!(add_light(rtv, get_light(split))))
				return (0);
		if (!ft_strncmp(split[0], "object:", 7))
			if (!(add_obj(rtv, pars_obj(split))))
				return (0);
		free_split(split);
		free(line);
	}
	return (1);
}

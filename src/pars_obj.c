/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:44:21 by student           #+#    #+#             */
/*   Updated: 2020/08/19 16:44:51 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_obj		*get_sphere(char **split)
{
	t_obj	*sphere;
	int		tab[9];
	int		i;

	i = -1;
	split += 2;
	if (split_len(split) != 9)
		return (NULL);
	while (split[++i])
		tab[i] = ft_atoi(split[i]);
	sphere = ft_newsphere(ft_newdot(tab[0], tab[1], tab[2]), tab[3],
			ft_newcolor(tab[4], tab[5], tab[6]));
	sphere->reflect = (tab[7] > 100) ? 1 : (double)tab[7] / 100;
	sphere->s = tab[8];
	return (sphere);
}

static t_obj		*get_cone(char **split)
{
	t_obj	*cone;
	int		tab[12];
	int		i;
	double	fi;

	i = -1;
	split += 2;
	if (split_len(split) != 12)
		return (NULL);
	while (split[++i])
		tab[i] = ft_atoi(split[i]);
	fi = (double)tab[9] / 100;
	cone = ft_newcone(ft_newdot(tab[0], tab[1], tab[2]),
			ft_newcolor(tab[3], tab[4], tab[5]),
			ft_newdot(tab[6], tab[7], tab[8]), fi);
	cone->reflect = (tab[10] > 100) ? 1 : (double)tab[10] / 100;
	if (fi > 0.5)
		cone->reflect = 0;
	cone->s = tab[11];
	return (cone);
}

static t_obj		*get_cylinder(char **split)
{
	t_obj	*cylinder;
	int		tab[12];
	int		i;

	i = -1;
	split += 2;
	if (split_len(split) != 12)
		return (NULL);
	while (split[++i])
		tab[i] = ft_atoi(split[i]);
	cylinder = ft_newcylinder(ft_newdot(tab[0], tab[1], tab[2]), tab[3],
			ft_newcolor(tab[4], tab[5], tab[6]),
			ft_newdot(tab[7], tab[8], tab[9]));
	cylinder->reflect = (tab[10] > 100) ? 1 : (double)tab[10] / 100;
	cylinder->s = tab[11];
	return (cylinder);
}

static t_obj		*get_plane(char **split)
{
	t_obj	*plane;
	int		tab[11];
	int		i;

	i = -1;
	split += 2;
	if (split_len(split) != 11)
		return (NULL);
	while (split[++i])
		tab[i] = ft_atoi(split[i]);
	plane = ft_newplane(ft_newdot(tab[0], tab[1], tab[2]),
			ft_newcolor(tab[3], tab[4], tab[5]),
			ft_newdot(tab[6], tab[7], tab[8]));
	plane->reflect = (tab[9] > 100) ? 1 : (double)tab[9] / 100;
	plane->s = tab[10];
	return (plane);
}

t_obj				*pars_obj(char **split)
{
	if (!ft_strncmp(split[1], "SPHERE", 6))
		return (get_sphere(split));
	if (!ft_strncmp(split[1], "CONE", 4))
		return (get_cone(split));
	if (!ft_strncmp(split[1], "CYLINDER", 4))
		return (get_cylinder(split));
	if (!ft_strncmp(split[1], "PLANE", 5))
		return (get_plane(split));
	return (NULL);
}

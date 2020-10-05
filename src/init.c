/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:05:19 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/28 11:05:20 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_count(int count[2], char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	count[0] = 0;
	count[1] = 0;
	fd = open(file, O_RDONLY, 0);
	while ((i = get_next_line(fd, &line)))
	{
		if (i < 0 || !line[0])
			return (0);
		if (!ft_strncmp(line, "light:", 6))
			count[0]++;
		if (!ft_strncmp(line, "object:", 7))
			count[1]++;
		free(line);
	}
	if (count[0] == 0 || count[1] == 0)
		return (0);
	close(fd);
	return (1);
}

t_rtv1		*init_struct(t_rtv1 *rtv, char *file)
{
	int		count[2];

	if (!(check_count(count, file)))
		ft_exit("Not valid file");
	if (!(rtv = (t_rtv1*)malloc(sizeof(t_rtv1))))
		ft_exit("malloc ERROR");
	if (!(rtv->win = (t_window*)malloc(sizeof(t_window))))
		ft_exit("malloc ERROR");
	if (!(rtv->prm = (t_param*)malloc(sizeof(t_param))))
		ft_exit("malloc ERROR");
	if (!(rtv->obj = (t_obj**)malloc(sizeof(t_obj) * count[1])))
		ft_exit("malloc ERROR");
	if (!(rtv->light = (t_light**)malloc(sizeof(t_light) * count[0])))
		ft_exit("malloc ERROR");
	if (!(rtv->mouse = (t_mouse*)malloc(sizeof(t_mouse))))
		ft_exit("malloc ERROR");
	rtv->lt_count = 0;
	rtv->obj_count = 0;
	if (!(pars_stract(rtv, file)))
		ft_exit("Not valid file!");
	return (rtv);
}

void		reset_param(t_rtv1 *rtv)
{
	rtv->prm->zoom = 0;
	rtv->prm->move_x = 0;
	rtv->prm->move_y = 0;
	rtv->prm->move_z = 0;
	rtv->prm->ang_x = 0;
	rtv->prm->ang_y = 0;
	rtv->prm->ang_z = 0;
	rtv->prm->rot_x = 0;
	rtv->prm->rot_y = 0;
	rtv->prm->rot_z = 0;
	rtv->prm->move_speed = 3;
	rtv->ref = 0;
	rtv->info = OFF;
}

void		add_img(t_rtv1 *rtv, t_window *win)
{
	pthread_t	threads[10];
	t_rtv1		rtvs[10];
	int			i;

	i = -1;
	mlx_clear_window(rtv->win->mlx, rtv->win->win);
	ft_bzero(rtv->win->data_ptr, WIDTH * HEIGHT * 4);
	while (++i < 10)
	{
		rtvs[i] = *rtv;
		rtvs[i].y = i * (HEIGHT / 10);
		rtvs[i].y_end = (i + 1) * (HEIGHT / 10);
		pthread_create(&threads[i], NULL, (void*(*)(void*))draw,
				(void*)&rtvs[i]);
	}
	while (--i >= 0)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(win->mlx, win->win, win->img_ptr, 0, 0);
	info(rtv);
}

void		start(t_rtv1 *rtv)
{
	reset_param(rtv);
	add_img(rtv, rtv->win);
	mouse_hook(rtv);
	mlx_key_hook(rtv->win->win, opt_key, rtv);
	mlx_loop(rtv->win->mlx);
}

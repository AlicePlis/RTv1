/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:34:16 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/12 18:21:40 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			main(int argc, char **argv)
{
	t_rtv1		*rtv;

	rtv = NULL;
	if (argc == 2)
	{
		rtv = init_struct(rtv, argv[1]);
		rtv->win->mlx = mlx_init();
		rtv->win->win = mlx_new_window(rtv->win->mlx, WIDTH, HEIGHT, "RTv1");
		rtv->win->img_ptr = mlx_new_image(rtv->win->mlx, WIDTH, HEIGHT);
		rtv->win->data_ptr = mlx_get_data_addr(rtv->win->img_ptr,
				&rtv->win->bpp, &rtv->win->sl, &rtv->win->end);
		ft_bzero(rtv->win->data_ptr, WIDTH * HEIGHT * 4);
		start(rtv);
		exit(0);
	}
	ft_exit("Rtv1 scene.rt");
}

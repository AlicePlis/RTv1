/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:37:49 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/13 12:37:50 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		add_frame_x(t_window *d, int x, int x_max, int y)
{
	while (x <= x_max)
	{
		mlx_pixel_put(d->mlx, d->win, x, y, 0x6282AA);
		x++;
	}
}

static void		add_frame_y(t_window *d, int y, int y_max, int x)
{
	while (y <= y_max)
	{
		mlx_pixel_put(d->mlx, d->win, x, y, 0x6282AA);
		y++;
	}
}

static void		add_sh(t_window *d)
{
	mlx_string_put(d->mlx, d->win, 70, 22, 0x688b, "CONTROL");
	mlx_string_put(d->mlx, d->win, 22, 52, 0x688b,
			"MOVE     : WASDQE");
	mlx_string_put(d->mlx, d->win, 22, 72, 0x688b,
			"SPEED    : + / -");
	mlx_string_put(d->mlx, d->win, 22, 92, 0x688b,
			"ROTATE X : 5 / 6");
	mlx_string_put(d->mlx, d->win, 22, 112, 0x688b,
			"ROTATE Y : 3 / 4");
	mlx_string_put(d->mlx, d->win, 22, 132, 0x688b,
			"ROTATE Z : 1 / 2");
	mlx_string_put(d->mlx, d->win, 22, 152, 0x688b,
			"REFLECT  : R");
	mlx_string_put(d->mlx, d->win, 22, 172, 0x688b,
			"RESET    : ENTER");
	mlx_string_put(d->mlx, d->win, 22, 232, 0x688b,
			"EXIT     : ESC ");
	add_frame_x(d, 10, 200, 10);
	add_frame_x(d, 10, 200, 285);
	add_frame_y(d, 10, 285, 10);
	add_frame_y(d, 10, 285, 200);
}

static void		add_menu(t_window *d)
{
	mlx_string_put(d->mlx, d->win, 68, 20, 0xf7f7f7, "CONTROL");
	mlx_string_put(d->mlx, d->win, 20, 50, 0xf7f7f7,
			"MOVE     : WASDQE ");
	mlx_string_put(d->mlx, d->win, 20, 70, 0xf7f7f7,
			"SPEED    : + / -");
	mlx_string_put(d->mlx, d->win, 20, 90, 0xf7f7f7,
			"ROTATE X : 5 / 6");
	mlx_string_put(d->mlx, d->win, 20, 110, 0xf7f7f7,
			"ROTATE Y : 3 / 4");
	mlx_string_put(d->mlx, d->win, 20, 130, 0xf7f7f7,
			"ROTATE Z : 1 / 2");
	mlx_string_put(d->mlx, d->win, 20, 150, 0xf7f7f7,
			"REFLECT  : R");
	mlx_string_put(d->mlx, d->win, 20, 170, 0xf7f7f7,
			"RESET    : ENTER");
	mlx_string_put(d->mlx, d->win, 20, 230, 0xf7f7f7,
			"EXIT     : ESC ");
	add_frame_x(d, 15, 195, 15);
	add_frame_x(d, 15, 195, 280);
	add_frame_y(d, 15, 280, 15);
	add_frame_y(d, 15, 280, 195);
}

void			info(t_rtv1 *rtv)
{
	if (rtv->info == OFF)
	{
		mlx_string_put(rtv->win->mlx, rtv->win->win,
				70, 22, 0x688b, "CONTROL [i]");
		mlx_string_put(rtv->win->mlx, rtv->win->win,
				68, 20, 0xf7f7f7, "CONTROL [i]");
	}
	else
	{
		add_sh(rtv->win);
		add_menu(rtv->win);
	}
}

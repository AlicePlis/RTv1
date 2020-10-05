/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:16:57 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/17 17:16:58 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	mouse_press(int button, int x, int y, t_rtv1 *rtv)
{
	t_param	*d;

	d = rtv->prm;
	if (button == 1)
	{
		if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
		{
			rtv->mouse->button1 = ON;
			rtv->mouse->x0 = x;
			rtv->mouse->y0 = y;
		}
	}
	if (button == 2)
	{
		rtv->mouse->button2 = ON;
		rtv->mouse->x0 = x;
		rtv->mouse->y0 = y;
	}
	if (button == 4 || button == 5)
	{
		d->move_z += (button == 5) ? 100 * d->move_speed : -100 * d->move_speed;
		add_img(rtv, rtv->win);
	}
	return (0);
}

static int	mouse_release(int button, int x, int y, t_rtv1 *rtv)
{
	(void)x;
	(void)y;
	if (button == 1)
		rtv->mouse->button1 = OFF;
	if (button == 2)
		rtv->mouse->button2 = OFF;
	return (0);
}

static int	mouse_move(int x, int y, t_rtv1 *rtv)
{
	if (rtv->mouse->button1 == ON)
	{
		rtv->mouse->x = x - rtv->mouse->x0;
		rtv->mouse->y = y - rtv->mouse->y0;
		rtv->mouse->x0 = x;
		rtv->mouse->y0 = y;
		if (rtv->mouse->button2 == ON)
		{
			rtv->prm->move_x += rtv->mouse->x * rtv->prm->move_speed;
			rtv->prm->move_y += rtv->mouse->y * rtv->prm->move_speed;
		}
		else
		{
			rtv->prm->ang_y += rtv->mouse->x / 400;
			if (rtv->prm->ang_y >= 6.28319 || rtv->prm->ang_y <= -6.28319)
				rtv->prm->ang_y = 0;
			rtv->prm->ang_x -= rtv->mouse->y / 400;
			if (rtv->prm->ang_x >= 6.28319 || rtv->prm->ang_x <= -6.28319)
				rtv->prm->ang_x = 0;
		}
		add_img(rtv, rtv->win);
	}
	return (0);
}

static int	f_close(t_rtv1 *rtv)
{
	(void)rtv;
	exit(0);
}

void		mouse_hook(t_rtv1 *rtv)
{
	mlx_hook(rtv->win->win, 4, 0, mouse_press, rtv);
	mlx_hook(rtv->win->win, 5, 0, mouse_release, rtv);
	mlx_hook(rtv->win->win, 6, 0, mouse_move, rtv);
	mlx_hook(rtv->win->win, 17, 0, f_close, rtv);
}

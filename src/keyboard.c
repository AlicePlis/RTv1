/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:57:49 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/11 15:57:50 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	param_key(int key, t_rtv1 *rtv)
{
	if (key == 0 || key == 2)
		rtv->prm->move_x += (key == 2) ? 100 : -100;
	if (key == 13 || key == 1)
		rtv->prm->move_y += (key == 13) ? 100 : -100;
	if (key == 12 || key == 14)
		rtv->prm->move_z += (key == 14) ? 100 : -100;
	if (key == 36)
		reset_param(rtv);
	if (key == 15)
	{
		if (rtv->ref < 6)
			rtv->ref += 1;
		else
			rtv->ref = 0;
	}
	if (key == 34)
		rtv->info = (rtv->info == ON) ? OFF : ON;
	add_img(rtv, rtv->win);
}

static void	rotate_key(int key, t_rtv1 *rtv)
{
	if (key == 20 || key == 21)
		rtv->prm->ang_x += (key == 20) ? 0.2 : -0.2;
	if (key == 22 || key == 23)
		rtv->prm->ang_y += (key == 23) ? 0.2 : -0.2;
	if (key == 18 || key == 19)
		rtv->prm->ang_z += (key == 18) ? 0.2 : -0.2;
	add_img(rtv, rtv->win);
}

int			opt_key(int key, t_rtv1 *rtv)
{
	if (key == 53)
		exit(0);
	if (key >= 0 || key <= 2 || key >= 12 || key <= 14 ||
		key == 36 || key == 15 || key == 34)
		param_key(key, rtv);
	if (key == 69 || key == 78)
	{
		rtv->prm->zoom *= (key == 69) ? 1.1 : 0.9;
		add_img(rtv, rtv->win);
	}
	if (key >= 18 || key <= 23)
		rotate_key(key, rtv);
	if (key == 24 || key == 27)
		rtv->prm->move_speed *= (key == 24) ? 2 : 0.5;
	return (0);
}

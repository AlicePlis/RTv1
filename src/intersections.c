/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:32:25 by student           #+#    #+#             */
/*   Updated: 2020/07/09 15:32:31 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		solution_of_q(double a, double b, double d, double t[2])
{
	double	tmp;

	t[0] = (-b - sqrt(d)) / (2 * a);
	t[1] = (-b + sqrt(d)) / (2 * a);
	/*if ((t[0] <= t[1] && t[0] >= 0) || (t[0] >= 0 && t[1] < 0))
		return (t[0]);*/
	if ((t[1] <= t[0] && t[1] >= 0) || (t[1] >= 0 && t[0] < 0))
	{
		tmp = t[1];
		t[1] = t[0];
		t[0] = tmp;
	}
}

void		ft_sphere(t_xyz d, t_obj *obj, t_xyz oc, double t[2])
{
	double	k[3];
	double	di;

	t[0] = -1;
	k[0] = ft_vdot(d, d);
	k[1] = 2 * ft_vdot(oc, d);
	k[2] = ft_vdot(oc, oc) - (obj->r * obj->r);
	di = k[1] * k[1] - 4 * k[0] * k[2];
	if (di >= 0)
		solution_of_q(k[0], k[1], di, t);
}

void		ft_cylinder(t_xyz d, t_obj *obj, t_xyz oc, double t[2])
{
	double	k[3];
	double	di;

	t[0] = -1;
	k[0] = ft_vdot(d, d) - ft_vdot(d, obj->norm) * ft_vdot(d, obj->norm);
	k[1] = 2 * (ft_vdot(d, oc) - ft_vdot(d, obj->norm) *
			ft_vdot(oc, obj->norm));
	k[2] = ft_vdot(oc, oc) - ft_vdot(oc, obj->norm) * ft_vdot(oc, obj->norm)
			- obj->r * obj->r;
	di = k[1] * k[1] - 4 * k[0] * k[2];
	if (di >= 0)
		solution_of_q(k[0], k[1], di, t);
}

void		ft_cone(t_xyz d, t_obj *obj, t_xyz oc, double t[2])
{
	double	k[3];
	double	di;

	t[0] = -1;
	k[0] = ft_vdot(d, d) - (1 + obj->tg * obj->tg) * ft_vdot(d, obj->norm)
			* ft_vdot(d, obj->norm);
	k[1] = 2 * (ft_vdot(oc, d) - (1 + obj->tg * obj->tg) * ft_vdot(d, obj->norm)
			* ft_vdot(oc, obj->norm));
	k[2] = ft_vdot(oc, oc) - (1 + obj->tg * obj->tg) * ft_vdot(oc, obj->norm)
			* ft_vdot(oc, obj->norm);
	di = k[1] * k[1] - 4 * k[0] * k[2];
	if (di >= 0)
		solution_of_q(k[0], k[1], di, t);
}

void		ft_plane(t_xyz d, t_obj *obj, t_xyz oc, double t[2])
{
	double	k[2];

	t[0] = -1;
	k[0] = ft_vdot(oc, obj->norm);
	k[1] = ft_vdot(d, obj->norm);
	if (k[1] == 0 || (k[0] < 0 && k[1] < 0) || (k[0] > 0 && k[1] > 0))
		return ;
	t[0] = -k[0] / k[1];
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:21:40 by student           #+#    #+#             */
/*   Updated: 2020/08/20 14:22:29 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_rays			swap_ray(t_rays ray)
{
	ray.o = ray.p;
	ray.d = ray.l;
	return (ray);
}

static double	m_cone(t_xyz p, t_obj *obj)
{
	double	len_ob;
	double	len_os;
	double	m;
	t_xyz	ob;

	ob = ft_vsub(p, obj->c);
	len_ob = sqrt(ft_vdot(ob, ob));
	len_os = sqrt(ft_vdot(obj->axis, obj->axis));
	m = (len_ob / cosf(obj->fi)) / len_os;
	if (ob.y * obj->axis.y > 0)
		return (m);
	else
		return (m * (-1.0));
}

t_rays			add_rays(t_xyz d, t_obj *obj, t_xyz o, double t)
{
	t_rays	ray;
	double	m;

	ray.v = ft_vmult(d, -1);
	ray.p = ft_vadd(o, ft_vmult(d, t));
	ray.n = ft_vnorm(ft_vsub(ray.p, obj->c));
	if (obj->type == CYLINDER)
	{
		m = ft_vdot(d, obj->norm) * t + ft_vdot(ft_vsub(o, obj->c),
				obj->norm);
		ray.n = ft_vnorm(ft_vsub(ft_vsub(ray.p, obj->c),
				ft_vmult(obj->norm, m)));
		if (ft_vdot(d, ray.n) > 0.0001)
			ray.n = ft_vmult(ray.n, -1);
	}
	if (obj->type == CONE)
		ray.n = ft_vnorm(ft_vsub(ray.p, ft_vadd(obj->c,
				ft_vmult(obj->axis, m_cone(ray.p, obj)))));
	if (obj->type == PLANE)
	{
		if (ft_vdot(d, obj->norm) < 0)
			ray.n = obj->norm;
		ray.n = ft_vmult(obj->norm, -1);
	}
	return (ray);
}

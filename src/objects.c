/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:37:49 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/13 12:37:50 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_xyz	ft_newdot(double x, double y, double z)
{
	t_xyz	new_dot;

	new_dot.x = x;
	new_dot.y = y;
	new_dot.z = z;
	return (new_dot);
}

t_obj	*ft_newsphere(t_xyz c, int r, t_color color)
{
	t_obj	*new_obj;

	if (!(new_obj = (t_obj*)malloc(sizeof(t_obj))))
		return (NULL);
	new_obj->c = c;
	new_obj->r = r;
	new_obj->color = color;
	new_obj->ft_obj_ray = &ft_sphere;
	new_obj->type = SPHERE;
	return (new_obj);
}

t_obj	*ft_newcylinder(t_xyz c, int r, t_color color, t_xyz axis)
{
	t_obj	*new_obj;

	if (!(new_obj = (t_obj*)malloc(sizeof(t_obj))))
		return (NULL);
	new_obj->r = r;
	new_obj->c = c;
	new_obj->axis = axis;
	new_obj->color = color;
	new_obj->norm = ft_vnorm(axis);
	new_obj->ft_obj_ray = &ft_cylinder;
	new_obj->type = CYLINDER;
	return (new_obj);
}

t_obj	*ft_newcone(t_xyz c, t_color color, t_xyz axis, double fi)
{
	t_obj	*new_obj;

	if (!(new_obj = (t_obj*)malloc(sizeof(t_obj))))
		return (NULL);
	new_obj->c = c;
	new_obj->axis = axis;
	new_obj->color = color;
	new_obj->norm = ft_vnorm(axis);
	new_obj->fi = fi;
	new_obj->tg = tanf(fi);
	new_obj->type = CONE;
	new_obj->ft_obj_ray = &ft_cone;
	return (new_obj);
}

t_obj	*ft_newplane(t_xyz c, t_color color, t_xyz axis)
{
	t_obj	*new_obj;

	if (!(new_obj = (t_obj*)malloc(sizeof(t_obj))))
		return (NULL);
	new_obj->c = c;
	new_obj->axis = axis;
	new_obj->color = color;
	new_obj->k = ft_vdot(c, axis);
	new_obj->type = PLANE;
	new_obj->ft_obj_ray = &ft_plane;
	new_obj->norm = ft_vnorm(axis);
	new_obj->k = ft_vdot(c, axis);
	return (new_obj);
}

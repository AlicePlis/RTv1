/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:37:49 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/13 12:37:50 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_xyz	ft_vreflect(t_xyz b, t_xyz c)
{
	t_xyz	a;

	a = ft_vmult(b, 2);
	a = ft_vmult(a, ft_vdot(b, c));
	a = ft_vsub(a, c);
	return (a);
}

t_xyz	ft_vadd(t_xyz a, t_xyz b)
{
	t_xyz	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_xyz	ft_vsub(t_xyz a, t_xyz b)
{
	t_xyz	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_xyz	ft_vmult(t_xyz a, double i)
{
	t_xyz	c;

	c.x = a.x * i;
	c.y = a.y * i;
	c.z = a.z * i;
	return (c);
}

t_xyz	ft_vnorm(t_xyz a)
{
	return (ft_vmult(a, 1.0 / ft_vlenght(a)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:32:25 by student           #+#    #+#             */
/*   Updated: 2020/07/09 15:32:31 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_xyz	rotate_y(t_xyz dot, t_param *data)
{
	t_xyz	new_dot;

	new_dot.y = dot.y;
	new_dot.x = (cos(data->ang_y) * dot.x + sin(data->ang_y) * dot.z);
	new_dot.z = (-sin(data->ang_y) * dot.x + cos(data->ang_y) * dot.z);
	return (new_dot);
}

static t_xyz	rotate_x(t_xyz dot, t_param *data)
{
	t_xyz	new_dot;

	new_dot.x = dot.x;
	new_dot.y = cos(data->ang_x) * dot.y - sin(data->ang_x) * dot.z;
	new_dot.z = sin(data->ang_x) * dot.y + cos(data->ang_x) * dot.z;
	return (new_dot);
}

static t_xyz	rotate_z(t_xyz dot, t_param *data)
{
	t_xyz	new_dot;

	new_dot.z = dot.z;
	new_dot.x = cos(data->ang_z) * dot.x - sin(data->ang_z) * dot.y;
	new_dot.y = sin(data->ang_z) * dot.x + cos(data->ang_z) * dot.y;
	return (new_dot);
}

t_xyz			rotate(t_xyz dot, t_param *prm)
{
	dot = rotate_x(dot, prm);
	dot = rotate_y(dot, prm);
	dot = rotate_z(dot, prm);
	return (dot);
}

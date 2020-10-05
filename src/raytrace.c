/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:31:22 by student           #+#    #+#             */
/*   Updated: 2020/07/09 13:35:49 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_put_image(t_rtv1 *rtv, int x, int y, int color)
{
	int		*img;

	img = (int*)rtv->win->data_ptr;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		*(img + x + y * WIDTH) = color;
}

t_obj			*find_closest(t_rtv1 *rtv, double ft[2], t_rays ray, double tn[2])
{
	double	closest_t;
	double	t[2];
	int		i;
	t_obj	*closest;

	closest_t = 500000;
	closest = NULL;
	i = -1;
	while (++i < rtv->obj_count && rtv->obj[i])
	{
		rtv->obj[i]->ft_obj_ray(ray.d, rtv->obj[i],
				ft_vsub(ray.o, rtv->obj[i]->c), t);
		if (t[0] >= ft[MIN] && t[0] <= ft[MAX] && t[0] < closest_t)
		{
			closest_t = t[0];
			closest = rtv->obj[i];
		}
	}
	if (closest)
	{
		tn[0] = closest_t;
		tn[1] = t[1];
	}
	return (closest);
}

t_color			raytrace(t_rtv1 *rtv, t_rays ray, double frames_t[2], int rec)
{
	t_obj	*tmp;
	t_color color;
	t_color	rf_color;
	double	t[2];

	color = ft_newcolor(0, 0, 0);
	tmp = find_closest(rtv, frames_t, ray, t);
	if (tmp)
	{
		ray = add_rays(ray.d, tmp, ray.o, t[0]);
		color = rgb_color_mult(tmp->color, light(rtv, ray, tmp));
		if (rec == 0 || tmp->reflect == 0)
			return (color);
		ray.r = ft_vreflect(ray.n, ray.v);
		frames_t[MIN] = 0.001;
		frames_t[MAX] = 50000;
		ray.o = ray.p;
		ray.d = ray.r;
		rf_color = raytrace(rtv, ray, frames_t, --rec);
		if (rgb_to_hex(rf_color) != 0x000000)
			return (color_add(rgb_color_mult(color, 1.0 - tmp->reflect),
					rgb_color_mult(rf_color, tmp->reflect)));
	}
	return (color);
}

static void		parsdraw(t_param *prm, t_rtv1 *rtv)
{
	int		x;
	int		y;
	int		color;
	double	frames_t[2];
	t_rays	ray;

	frames_t[MIN] = 0;
	frames_t[MAX] = 50000;
	y = rtv->y - 1;
	while (++y < rtv->y_end)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ray.o = ft_newdot(rtv->o.x + prm->move_x, rtv->o.y + prm->move_y,
					rtv->o.z + prm->move_z);
			ray.d = ft_vsub(ft_newdot(x, y, 800),
					ft_newdot(WIDTH / 2, HEIGHT / 2, 0));
			ray.d = rotate(ray.d, rtv->prm);
			color = rgb_to_hex(raytrace(rtv, ray, frames_t, rtv->ref));
			if (color != 0x000000)
				ft_put_image(rtv, x, y, color);
		}
	}
}

void			draw(t_rtv1 *rtv)
{
	parsdraw(rtv->prm, rtv);
}

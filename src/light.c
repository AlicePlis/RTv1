/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:46:37 by student           #+#    #+#             */
/*   Updated: 2020/08/19 17:46:46 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	diffusion(t_rays ray, double bright)
{
	double	i;
	double	ndl;

	i = 0.0;
	ndl = ft_vdot(ray.n, ray.l);
	if (ndl > 0)
		i = bright * ndl / (ft_vlenght(ray.n) * ft_vlenght(ray.l));
	return (i);
}

static double	reflection(int s, t_rays ray, double bright)
{
	double	i;
	double	rdv;

	i = 0.0;
	if (s > 0)
	{
		ray.r = ft_vreflect(ray.n, ray.l);
		rdv = ft_vdot(ray.r, ray.v);
		if (rdv > 0)
			i = bright * pow(rdv / (ft_vlenght(ray.r) *
					ft_vlenght(ray.v)), s);
	}
	return (i);
}

double			light(t_rtv1 *rtv, t_rays ray, t_obj *obj)
{
	double		i;
	double		frames_t[2];
	int			j;
	double		t;

	i = 0.0;
	frames_t[MIN] = 0.01;
	j = -1;
	while (++j < rtv->lt_count)
	{
		if (rtv->light[j]->type == AMB)
			i += rtv->light[j]->bright;
		else
		{
			ray.l = ft_vmult(rtv->light[j]->c, 1);
			if (rtv->light[j]->type == POINT)
				ray.l = ft_vsub(rtv->light[j]->c, ray.p);
			frames_t[MAX] = rtv->light[j]->type;
			ray = swap_ray(ray);
			if (!find_closest(rtv, frames_t, ray, &t))
			{
				i += diffusion(ray, rtv->light[j]->bright) +
					 reflection(obj->s, ray, rtv->light[j]->bright);
			}
		}
	}
	return (i);
}

t_light			*ft_newlight(t_xyz c, int type, float bright)
{
	t_light		*new_light;

	if (!(new_light = (t_light*)malloc(sizeof(t_light))))
		return (NULL);
	new_light->c = c;
	new_light->type = type;
	new_light->bright = bright;
	return (new_light);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:33:30 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/22 18:33:31 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	color_intens(int c, double i)
{
	int		a;

	a = (c * i > 255) ? 255 : c * i;
	return (a);
}

int			rgb_to_hex(t_color c)
{
	int		r;
	int		g;
	int		b;

	r = c.red;
	g = c.green;
	b = c.blue;
	return (r << 16) + (g << 8) + b;
}

t_color		rgb_color_mult(t_color c, double i)
{
	t_color		color;

	color.red = color_intens(c.red, i);
	color.green = color_intens(c.green, i);
	color.blue = color_intens(c.blue, i);
	return (color);
}

t_color		color_add(t_color a, t_color b)
{
	t_color		new_color;

	new_color.red = (a.red + b.red > 255) ? 255 : a.red + b.red;
	new_color.green = (a.green + b.green > 255) ? 255 : a.green + b.green;
	new_color.blue = (a.blue + b.blue > 255) ? 255 : a.blue + b.blue;
	return (new_color);
}

t_color		ft_newcolor(int r, int g, int b)
{
	t_color		new_color;

	if (r > 255 || r < 0)
		r = (r > 255) ? 255 : 0;
	new_color.red = r;
	if (g > 255 || g < 0)
		g = (g > 255) ? 255 : 0;
	new_color.green = g;
	if (b > 255 || b < 0)
		b = (b > 255) ? 255 : 0;
	new_color.blue = b;
	return (new_color);
}

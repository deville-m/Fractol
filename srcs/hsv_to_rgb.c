/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:39:36 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 23:09:22 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_graphics.h"

static t_pixel	new_color(double r, double g, double b)
{
	t_pixel res;

	res.color.r = (int)(r * 255);
	res.color.g = (int)(g * 255);
	res.color.b = (int)(b * 255);
	return (res);
}

t_pixel			hsv_to_rgb(double h, double s, double v)
{
	double	c;
	double	x;
	double	m;

	c = v * s;
	h = h / 60.0;
	x = c * (1.0 - fabs(fmod(h, 2.0) - 1.0));
	m = v - c;
	if (h >= 0 && h < 1)
		return (new_color(c + m, x + m, m));
	else if (h >= 1 && h < 2)
		return (new_color(x + m, c + m, m));
	else if (h >= 2 && h < 3)
		return (new_color(m, c + m, x + m));
	else if (h >= 3 && h < 4)
		return (new_color(m, x + m, c + m));
	else if (h >= 4 && h < 5)
		return (new_color(x + m, m, c + m));
	else if (h >= 5 && h < 6)
		return (new_color(c + m, m, x + m));
	else
		return (new_color(m, m, m));
}

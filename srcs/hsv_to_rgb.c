/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:39:36 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 18:07:16 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_graphics.h"

static t_pixel	new_color(double r, double g, double b)
{
	t_pixel res;

	res.color.r = (int)r * 255;
	res.color.g = (int)g * 255;
	res.color.b = (int)b * 255;
	return (res);
}

t_pixel			hsv_to_rgb(double h, double s, double v)
{
	t_pixel	res;
	double	c;
	double	x;
	double	m;

	c = v * s;
	x = c * (1.0 - fabs(fmod(h / 60.0, 2) - 1.0));
	if (h >= 0 && h < 60.0)
		return (new_color(c + m, x + m, m));
	else if (h >= 60.0 && h < 120.0)
		return (new_color(x + m, c + m, m));
	else if (h >= 120.0 && h < 180.0)
		return (new_color(m, c + m, x + m));
	else if (h >= 180.0 && h < 240.0)
		return (new_color(m, x + m, c + m));
	else if (h >= 240.0 && h < 300.0)
		return (new_color(x + m, m, c + m));
	else if (h >= 300.0 && h < 360.0)
		return (new_color(c + m, m, x + m));
	else
		return (new_color(m, m, m));
}


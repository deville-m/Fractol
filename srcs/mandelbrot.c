/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:02:42 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/13 22:24:21 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include "fractol.h"
#include "ft_graphics.h"

static t_pixel	palette(int iteration, int maxit)
{
	t_pixel res;

	res.color.r = iteration * 0XFF / maxit;
	res.color.g = iteration * 0XFF / maxit;
	res.color.b = iteration * 0XFF / maxit;
	return (res);
}

static int		escape_time(double x0, double y0, int maxit)
{
	int		i;
	double	x;
	double	y;
	double	xtemp;

	i = 0;
	x = 0.;
	y = 0.;
	while (x * x + y * y < 4 && i < maxit)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		++i;
	}
	return (i);
}

void			*mandelbrot(void *args)
{
	t_pargs		*pargs;
	t_2dvector	pixel;
	int			iteration;

	pargs = (t_pargs *)args;
	pixel.y = pargs->miny;
	while (pixel.y < pargs->maxy)
	{
		pixel.x = 0;
		while (pixel.x < pargs->img->width)
		{
			iteration = escape_time(pixel.x * pargs->pixel.x + pargs->cmin.x,
									pixel.y * pargs->pixel.y + pargs->cmin.y,
									pargs->maxit);
			put_pixel(pargs->img, pixel, palette(iteration, pargs->maxit));
			++pixel.x;
		}
		++pixel.y;
	}
	return (NULL);
}

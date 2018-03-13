/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:02:42 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/13 16:52:13 by mdeville         ###   ########.fr       */
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

	if (iteration / maxit <= 0.01)
		res.hex = BLUE;
	else if (iteration / maxit <= 0.1)
		res.hex = CYAN;
	else if (iteration / maxit <= 0.2)
		res.hex = GREEN;
	else if (iteration / maxit <= 0.5)
		res.hex = INDIGO;
	else if (iteration / maxit <= 0.75)
		res.hex = RED;
	else
		res.hex = GOLD;
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

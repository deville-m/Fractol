/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:10:42 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 14:57:19 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

static int		escape_time(double x0, double y0, t_2dvector c, int maxit)
{
	int		i;
	double	x;
	double	y;
	double	xtemp;

	i = 0;
	x = c.x;
	y = c.y;
	while (x * x + y * y < 4 && i < maxit)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		++i;
	}
	return (i);
}

void			*julia(void *args)
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
									pargs->julia_c,
									pargs->maxit);
			put_pixel(pargs->img, pixel, palette(iteration, pargs->maxit));
			++pixel.x;
		}
		++pixel.y;
	}
	return (NULL);
}

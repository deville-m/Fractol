/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:02:42 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 21:16:31 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include "fractol.h"
#include "ft_graphics.h"

double		m_normalize(t_2dvector *point, t_2dvector var, int maxit)
{
	int		i;
	double	x;
	double	y;
	double	xtemp;

	(void)var;
	i = 0;
	x = 0.;
	y = 0.;
	while (x * x + y * y < 4 && i < maxit)
	{
		xtemp = x * x - y * y + point->x;
		y = 2 * x * y + point->y;
		x = xtemp;
		++i;
	}
	point->x = x;
	point->y = y;
	return (i + 1 - log10(log10(sqrt(x * x + y * y))) / log10(2));
}

double		m_escape(t_2dvector *point, t_2dvector var, int maxit)
{
	int		i;
	double	x;
	double	y;
	double	xtemp;

	(void)var;
	i = 0;
	x = 0.;
	y = 0.;
	while (x * x + y * y < 4 && i < maxit)
	{
		xtemp = x * x - y * y + point->x;
		y = 2 * x * y + point->y;
		x = xtemp;
		++i;
	}
	point->x = x;
	point->y = y;
	return (i);
}

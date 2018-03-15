/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:02:42 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/15 15:03:10 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include "fractol.h"
#include "ft_graphics.h"

double		m_normalize(double x0, double y0, t_2dvector var, int maxit)
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
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		++i;
	}
	return (i + 1 - log10(log10(sqrt(x * x + y * y))) / log10(2));
}

double		m_escape(double x0, double y0, t_2dvector var, int maxit)
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
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		++i;
	}
	return (i);
}

double		tricorn(double x0, double y0, t_2dvector var, int maxit)
{
	int		i;
	double	x;
	double	y;
	double	xtemp;

	(void)var;
	i = 0;
	x = x0;
	y = y0;
	while (x * x + y * y < 4 && i < maxit)
	{
		xtemp = x * x - y * y + x0;
		y = -2 * x * y + y0;
		x = xtemp;
		++i;
	}
	return (i);
}

double		burning_ship(double x0, double y0, t_2dvector var, int maxit)
{
	int		i;
	double	x;
	double	y;
	double	xtemp;

	(void)var;
	i = 0;
	x = 0;
	y = 0;
	while (x * x + y * y < 4 && i < maxit)
	{
		xtemp = x * x - y * y + x0;
		y = fabs(-2 * x * y + y0);
		x = fabs(xtemp);
		++i;
	}
	return (i);
}

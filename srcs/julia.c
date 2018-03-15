/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:10:42 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/15 13:34:39 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fractol.h"
#include "ft_graphics.h"

double	j_escape(double x0, double y0, t_2dvector c, int maxit)
{
	int		i;
	double	xtemp;
	double	x;
	double	y;

	i = 0;
	x = x0;
	y = y0;
	while (x * x + y * y < 4 && i < maxit)
	{
		xtemp = x * x - y * y + c.x;
		y = 2 * x * y + c.y;
		x = xtemp;
		++i;
	}
	return (i);
}

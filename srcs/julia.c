/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:10:42 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 20:55:37 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fractol.h"
#include "ft_graphics.h"

double	j_escape(t_2dvector *point, t_2dvector c, int maxit)
{
	int		i;
	double	xtemp;
	double	x;
	double	y;

	i = 0;
	x = point->x;
	y = point->y;
	while (x * x + y * y < 4 && i < maxit)
	{
		xtemp = x * x - y * y + c.x;
		y = 2 * x * y + c.y;
		x = xtemp;
		++i;
	}
	point->x = x;
	point->y = y;
	return (i);
}

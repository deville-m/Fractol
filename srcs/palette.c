/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:41:48 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 22:59:17 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"
#include "fractol.h"

t_pixel	smooth(double smooth, int maxit, t_2dvector point)
{
	t_pixel res;

	(void)point;
	smooth /= maxit;
	res = hsv_to_rgb(360 * smooth, 1, 1);
	return (res);
}

t_pixel	monochrome(double smooth, int maxit, t_2dvector point)
{
	t_pixel res;

	(void)point;
	res = get_conf()->color;
	res.color.r = smooth * res.color.r / maxit;
	res.color.g = smooth * res.color.g / maxit;
	res.color.b = smooth * res.color.b / maxit;
	return (res);
}

t_pixel	zebra(double smooth, int maxit, t_2dvector point)
{
	t_pixel res;
	int		tmp;

	(void)point;
	tmp = (int)smooth;
	if (tmp == maxit)
		res.hex = 0X00000000;
	else if (tmp % 2)
		res.hex = 0X00FFFFFF;
	else
		res.hex = 0X00000000;
	return (res);
}

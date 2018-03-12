/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:47:03 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/08 15:48:07 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

static void		put_line_high(
							t_image *img,
							t_2dvector a,
							t_2dvector b,
							t_pixel color)
{
	t_2dvector	d;
	int			xi;
	int			diff;

	d.x = b.x - a.x;
	d.y = b.y - a.y;
	xi = 1;
	if (d.x < 0)
	{
		xi = -1;
		d.x = -d.x;
	}
	diff = 2 * d.x - d.y;
	while (a.y <= b.y)
	{
		put_pixel(img, a, color);
		if (diff > 0)
		{
			a.x += xi;
			diff -= 2 * d.y;
		}
		diff += 2 * d.x;
		a.y += 1;
	}
}

static void		put_line_low(
							t_image *img,
							t_2dvector a,
							t_2dvector b,
							t_pixel color)
{
	t_2dvector	d;
	int			yi;
	int			diff;

	d.x = b.x - a.x;
	d.y = b.y - a.y;
	yi = 1;
	if (d.y < 0)
	{
		yi = -1;
		d.y = -d.y;
	}
	diff = 2 * d.y - d.x;
	while (a.x <= b.x)
	{
		put_pixel(img, a, color);
		if (diff > 0)
		{
			a.y += yi;
			diff -= 2 * d.x;
		}
		diff += 2 * d.y;
		a.x += 1;
	}
}

void			put_line(
						t_image *img,
						t_2dvector a,
						t_2dvector b,
						t_pixel color)
{
	int	dist_y;
	int	dist_x;

	if ((a.x >= img->width || a.y >= img->height)
		&& (b.x >= img->width || a.y >= img->height))
		return ;
	dist_y = b.y - a.y;
	dist_y *= dist_y;
	dist_x = b.x - a.x;
	dist_x *= dist_x;
	if (dist_y < dist_x)
	{
		if (a.x > b.x)
			put_line_low(img, b, a, color);
		else
			put_line_low(img, a, b, color);
	}
	else
	{
		if (a.y > b.y)
			put_line_high(img, b, a, color);
		else
			put_line_high(img, a, b, color);
	}
}

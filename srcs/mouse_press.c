/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 00:58:11 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 15:35:09 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"
#include "ft_graphics.h"

int		mouse_press(int keycode, int x, int y, void *param)
{
	t_mlx		*mlx;
	t_conf		*conf;
	t_2dvector	pixel;
	t_2dvector	diff;
	t_2dvector	middle;

	conf = get_conf();
	conf->maxit = 20;
	mlx = (t_mlx *)param;
	diff.x = conf->max.x - conf->min.x;
	diff.y = conf->max.y - conf->min.y;
	pixel.x = diff.x / mlx->img->width;
	pixel.y = diff.y / mlx->img->height;
	if (keycode == 1)
	{
		middle.x = x * pixel.x + conf->min.x;
		middle.y = y * pixel.y + conf->min.y;
		conf->min.x = middle.x - diff.x / 4;
		conf->min.y = middle.y - diff.y / 4;
		conf->max.x = middle.x + diff.x / 4;
		conf->max.y = middle.y + diff.y / 4;
	}
	return (1);
}

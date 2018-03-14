/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:28:11 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 16:05:09 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"
#include "fractol.h"

int		mouse_hook(int x, int y, void *param)
{
	t_mlx		*mlx;
	t_conf		*conf;
	t_2dvector	pixel;

	conf = get_conf();
	if (conf->mode != 2)
		return (0);
	conf->maxit = 50;
	mlx = (t_mlx *)param;
	pixel.x = (conf->max.x - conf->min.x) / mlx->img->width;
	pixel.y = (conf->max.y - conf->min.y) / mlx->img->height;
	conf->julia_c.x = x * pixel.x + conf->min.x;
	conf->julia_c.y = y * pixel.y + conf->min.y;
	return (1);
}

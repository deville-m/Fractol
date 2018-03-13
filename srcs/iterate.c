/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:05:29 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/13 16:42:36 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <pthread.h>
#include "fractol.h"
#include "ft_graphics.h"
#include <stdio.h>

static inline t_pargs	init_arg(t_mlx *mlx, t_conf *conf)
{
	t_pargs arg;

	arg.img = mlx->img;
	arg.maxy = 0;
	arg.maxit = conf->maxit;
	arg.pixel.x = (conf->max.x - conf->min.x) / mlx->img->width;
	arg.pixel.y = (conf->max.y - conf->min.y) / mlx->img->height;
	arg.cmin.x = conf->min.x;
	arg.cmin.y = conf->min.y;
	return (arg);
}

void					iterate(t_mlx *mlx, t_conf *conf, void *(*f)(void *))
{
	pthread_t	threads[conf->nbthread];
	t_pargs		thargs[conf->nbthread];
	t_pargs		arg;
	int			i;
	int			chunk_size;

	chunk_size = mlx->img->height / conf->nbthread;
	arg = init_arg(mlx, conf);
	i = 0;
	while (i < conf->nbthread)
	{
		arg.miny = arg.maxy;
		if (i != conf->nbthread - 1)
			arg.maxy = arg.maxy + chunk_size;
		else
			arg.maxy = mlx->img->height;
		thargs[i] = arg;
		if (pthread_create(&threads[i], NULL, f, &thargs[i]))
			break ;
		++i;
	}
	while (--i >= 0)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
}

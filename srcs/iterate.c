/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:05:29 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/15 13:32:23 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <pthread.h>
#include "fractol.h"
#include "ft_graphics.h"
#include <stdio.h>

static void				*calc(void *args)
{
	t_pargs		*pargs;
	t_2dvector	pixel;
	double		iteration;

	pargs = (t_pargs *)args;
	pixel.y = pargs->miny;
	while (pixel.y < pargs->maxy)
	{
		pixel.x = 0;
		while (pixel.x < pargs->img->width)
		{
			iteration = pargs->calc(
					pixel.x * pargs->pixel.x + pargs->cmin.x,
					pixel.y * pargs->pixel.y + pargs->cmin.y,
					pargs->julia_c, pargs->maxit);
			put_pixel(
					pargs->img,
					pixel,
					pargs->palette(iteration, pargs->maxit));
			++pixel.x;
		}
		++pixel.y;
	}
	return (NULL);
}

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
	arg.julia_c = conf->julia_c;
	arg.calc = conf->calc;
	arg.palette = conf->palette;
	return (arg);
}

void					iterate(t_mlx *mlx, t_conf *conf)
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
		if (pthread_create(&threads[i], NULL, calc, &thargs[i]))
			break ;
		++i;
	}
	while (--i >= 0)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
}

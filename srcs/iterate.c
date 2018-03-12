/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:05:29 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/12 15:33:39 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "fractol.h"
#include "ft_graphics.h"

void	iterate(t_mlx *mlx, t_conf *conf, void *(*f)(void *))
{
	pthread_t	threads[conf->nbthread];
	int			i;
	int			tmp;

	tmp = HEIGHT / conf->nbthread;
	i = 0;
	while (i < conf->nbthread)
	{
		if (pthread_create(&threads[i], NULL, f, ))
		++i;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
}

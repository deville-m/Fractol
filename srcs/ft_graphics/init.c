/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:03:41 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/05 19:39:23 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_graphics.h"
#include "memory.h"
#include "ft_printf.h"

int		init(t_mlx *mlx, int width, int height, char *name)
{
	if (!(mlx->ptr = mlx_init()))
	{
		ft_fprintf(2, "Could not init mlx socket\n");
		return (0);
	}
	if (!(mlx->win = mlx_new_window(mlx->ptr, width, height, name)))
	{
		ft_fprintf(2, "Could not init mlx window\n");
		return (0);
	}
	if (!(mlx->img = new_image(mlx->ptr, width, height)))
	{
		ft_fprintf(2, "Could not init mlx image\n");
		mlx_destroy_window(mlx->ptr, mlx->win);
		return (0);
	}
	mlx->alloced = NULL;
	ft_bzero(mlx->keyboard, sizeof(mlx->keyboard));
	ft_bzero(mlx->mouse, sizeof(mlx->mouse));
	return (1);
}

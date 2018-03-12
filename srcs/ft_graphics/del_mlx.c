/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 21:14:45 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/05 21:54:11 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "ft_graphics.h"

void	del_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	del_image(mlx->ptr, &mlx->img);
	mlx->img = NULL;
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx->win = NULL;
}

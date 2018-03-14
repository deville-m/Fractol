/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:46:42 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 23:05:31 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include "ft_graphics.h"
#include "mlx_keycode.h"
#include "ft_printf.h"

int		init_hooks(t_mlx *mlx)
{
	if (!mlx
		|| !mlx_hook(mlx->win, 17, 1L << 17, exit_x, mlx)
		|| !mlx_hook(mlx->win, KEYPRESS, KEYPRESSMASK, key_hook, mlx)
		|| !mlx_hook(mlx->win, BUTTONPRESS, 1L << 2, mouse_press, mlx)
		|| !mlx_hook(mlx->win, 6, 1L << 6, mouse_hook, mlx))
	{
		ft_fprintf(2, "Failed to init hooks\n");
		return (0);
	}
	return (1);
}

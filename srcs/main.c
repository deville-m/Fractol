/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:33:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/13 18:12:56 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include "fractol.h"
#include "ft_graphics.h"
#include "mlx_keycode.h"
#include "ft_printf.h"

t_conf		*get_conf(void)
{
	static t_conf conf = {{-2.5, 1.}, {1., -1.}, {-1., -1.}, 10, 1};

	return (&conf);
}

int			main(int argc, char **argv)
{
	t_mlx		mlx;

	(void)argc;
	(void)argv;
	if (!init(&mlx, WIDTH, HEIGHT, "Fractol") || !init_hooks(&mlx))
		return (0);
	mlx_loop_hook(mlx.ptr, print_x, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}

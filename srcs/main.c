/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:33:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 23:31:34 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include "fractol.h"
#include "ft_graphics.h"
#include "mlx_keycode.h"
#include "ft_printf.h"
#include "ft_string.h"

t_conf		*get_conf(void)
{
	static t_conf conf = {{-2.5, 1.}, {1., -1.}, {0, 0}, 10, 1, 0, {0}, 0, 0};

	return (&conf);
}

int			main(int argc, char **argv)
{
	t_mlx		mlx;
	t_conf		*conf;

	if (argc != 2 || !(ft_strequ("-m", argv[1]) || ft_strequ("-j", argv[1])))
	{
		ft_fprintf(2, "usage: fractol [-m | -j]");
		return (0);
	}
	conf = get_conf();
	if (ft_strequ("-m", argv[1]))
	{
		conf->calc = m_escape;
		conf->palette = monochrome;
	}
	else
	{
		conf->calc = j_escape;
		conf->palette = smooth;
	}
	if (!init(&mlx, WIDTH, HEIGHT, "Fractol") || !init_hooks(&mlx))
		return (0);
	mlx_loop_hook(mlx.ptr, print_x, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}

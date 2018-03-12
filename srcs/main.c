/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:33:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/12 14:22:27 by mdeville         ###   ########.fr       */
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
	static t_conf conf = {{-2.5, 1.}, {1., -1.}, {-1., -1.}};

	return (&conf);
}

static int	compute_mandelbrot(double x0, double y0, int max)
{
	double	xtemp;
	double	x;
	double	y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y < 4 && i < max)
	{
		xtemp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtemp;
		++i;
	}
	return (i != max);
}

static void	print_mandelbrot(t_mlx *mlx, t_conf *conf, int max)
{
	t_pixel	color;
	color.hex = 0X00FF0000;
	t_2dvector	curr;
	t_2dvector	pixel;

	pixel.x = (conf->max.x - conf->min.x) / WIDTH;
	pixel.y = (conf->max.y - conf->min.y) / HEIGHT;
	curr.y = 0.;
	while (curr.y < HEIGHT)
	{
		curr.x = 0.;
		while (curr.x < WIDTH)
		{
			if (compute_mandelbrot(pixel.x * curr.x + conf->min.x, pixel.y * curr.y + conf->min.y, max))
				put_pixel(mlx->img, curr, color);
			++curr.x;
		}
		++curr.y;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
}

int			main(int argc, char **argv)
{
	t_mlx		mlx;
	t_conf		*conf;

	(void)argc;
	(void)argv;
	if (!init(&mlx, WIDTH, HEIGHT, "Fractol") || !init_hooks(&mlx))
		return (0);
	conf = get_conf();
	print_mandelbrot(&mlx, conf, 10000);
	mlx_loop(mlx.ptr);
	return (0);
}

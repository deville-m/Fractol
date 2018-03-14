/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:20:09 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 14:36:38 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "ft_graphics.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_pargs
{
	t_image		*img;
	t_2dvector	pixel;
	t_2dvector	cmin;
	t_2dvector	julia_c;
	int			miny;
	int			maxy;
	int			maxit;
}				t_pargs;

typedef struct	s_conf
{
	t_2dvector	min;
	t_2dvector	max;
	t_2dvector	julia_c;
	int			nbthread;
	int			maxit;
	int			mode;
}				t_conf;

t_conf	*get_conf(void);
void	iterate(t_mlx *mlx, t_conf *conf, void *(*f)(void *));
void	*mandelbrot(void *);
void	*julia(void *);
int		mouse_press(int keycode, int x, int y, void *param);
int		mouse_hook(int x, int y, void *param);
int		key_hook(int keycode, void *param);
int		print_x(void *param);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:52:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/12 14:20:51 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H

typedef struct			s_3dvector
{
	double				x;
	double				y;
	double				z;
}						t_3dvector;

typedef struct			s_2dvector
{
	double				x;
	double				y;
}						t_2dvector;

struct					s_color
{
	unsigned char		b;
	unsigned char		g;
	unsigned char		r;
	unsigned char		a;
};

typedef union			u_pixel
{
	int					hex;
	struct s_color		color;
}						t_pixel;

typedef struct			s_image
{
	void				*ptr;
	t_pixel				**data;
	int					width;
	int					height;
	int					bit_per_pixel;
	int					size_line;
	int					endian;
}						t_image;

typedef struct			s_mlx
{
	void				*alloced;
	void				*ptr;
	void				*win;
	t_image				*img;
	int					keyboard[280];
	int					mouse[8];
}						t_mlx;

int						init(t_mlx *mlx, int width, int height, char *name);
int						init_hooks(t_mlx *mlx);
int						put_pixel(
								t_image *img,
								t_2dvector p,
								t_pixel color);
void					put_line(
								t_image *img,
								t_2dvector a,
								t_2dvector b,
								t_pixel color);
t_image					*new_image(void *mlx_ptr, int height, int width);
void					clear_image(t_image *img);
void					del_image(void *mlx_ptr, t_image **img);
void					del_mlx(t_mlx *mlx);
int						exit_x(void *param);

#endif

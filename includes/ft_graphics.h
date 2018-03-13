/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:52:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/13 14:45:47 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H

# define WHITE 0X00FFFFFF
# define BLACK 0X00000000
# define BLUE 0X000000FF
# define GREEN 0X0000FF00
# define RED 0X00FF0000
# define MIDDLEGREY 0X007A7A7A
# define CYAN 0X0000FFFF
# define GOLD 0X00FFD700
# define INDIGO 0X004B0082

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

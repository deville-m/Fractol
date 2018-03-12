/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:50:40 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/05 19:30:45 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include "ft_graphics.h"

static t_pixel	**reshape(char *data, int size_line, int height)
{
	t_pixel	**tmp;
	int		i;

	if (!(tmp = (t_pixel **)malloc(sizeof(t_pixel *) * height)))
		return (NULL);
	i = 0;
	while (i < height)
	{
		tmp[i] = (t_pixel *)(data + i * size_line);
		++i;
	}
	return (tmp);
}

t_image			*new_image(void *mlx_ptr, int width, int height)
{
	t_image	*new;
	char	*tmp;

	if (!(new = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!(new->ptr = mlx_new_image(mlx_ptr, width, height)))
	{
		free(new);
		return (NULL);
	}
	new->width = width;
	new->height = height;
	tmp = mlx_get_data_addr(
							new->ptr,
							&new->bit_per_pixel,
							&new->size_line,
							&new->endian);
	if (!(new->data = reshape(tmp, new->size_line, new->height)))
	{
		mlx_destroy_image(mlx_ptr, new->ptr);
		free(new);
		return (NULL);
	}
	return (new);
}

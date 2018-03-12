/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 21:05:18 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/05 21:54:10 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "ft_graphics.h"

void	del_image(void *mlx_ptr, t_image **img)
{
	if (!img || !*img)
		return ;
	mlx_destroy_image(mlx_ptr, (*img)->ptr);
	free((*img)->data);
	free(*img);
	*img = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:39:23 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/12 14:21:24 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

void	clear_image(t_image *img)
{
	int i;
	int j;

	if (!img)
		return ;
	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			img->data[i][j].hex = 0X00000000;
			++j;
		}
		++i;
	}
}

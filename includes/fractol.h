/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:20:09 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/12 14:01:26 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "ft_graphics.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_conf
{
	t_2dvector	min;
	t_2dvector	max;
	t_2dvector	julia_c;
}				t_conf;

#endif

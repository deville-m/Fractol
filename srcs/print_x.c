/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:51:21 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 20:59:26 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_graphics.h"

int		print_x(void *param)
{
	t_conf *conf;

	conf = get_conf();
	iterate(param, conf);
	conf->maxit += 1;
	return (1);
}

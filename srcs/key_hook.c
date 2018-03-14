/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:20:07 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/14 15:34:40 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_graphics.h"
#include "mlx_keycode.h"

int		zoom_key(int keycode, t_conf *conf)
{
	t_2dvector diff;

	diff.x = (conf->max.x - conf->min.x) / 4;
	diff.y = (conf->max.y - conf->min.y) / 4;
	if (keycode == NKPL_KEY)
	{
		conf->min.x += diff.x;
		conf->min.y += diff.y;
		conf->max.x -= diff.x;
		conf->max.y -= diff.y;
	}
	else if (keycode == NKMN_KEY)
	{
		conf->min.x -= diff.x;
		conf->min.y -= diff.y;
		conf->max.x += diff.x;
		conf->max.y += diff.y;
	}
	else
		return (0);
	return (1);
}

int		move_key(int keycode, t_conf *conf)
{
	int		sign;
	double	tmp;

	sign = (keycode == DOWN_KEY || keycode == RIGHT_KEY) ? 1: -1;
	if (keycode == UP_KEY || keycode == DOWN_KEY)
	{
		tmp = (conf->max.y - conf->min.y) / 20;
		conf->min.y = conf->min.y + sign * tmp;
		conf->max.y = conf->max.y + sign * tmp;
	}
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
	{
		tmp = (conf->max.x - conf->min.x) / 20;
		conf->min.x = conf->min.x + sign * tmp;
		conf->max.x = conf->max.x + sign * tmp;
	}
	else
		return (0);
	return (1);
}

int		key_hook(int keycode, void *param)
{
	t_conf	*conf;

	conf = get_conf();
	if (keycode == ESC_KEY)
		exit_x(param);
	else if (move_key(keycode, conf) || zoom_key(keycode, conf))
		conf->maxit = 20;
	return (1);
}

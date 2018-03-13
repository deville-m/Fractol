/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:20:07 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/13 17:41:48 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"
#include "mlx_keycode.h"

int		key_hook(int keycode, void *param)
{
	if (keycode == ESC_KEY)
		exit_x(param);
	return (1);
}

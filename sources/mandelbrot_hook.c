/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:00:38 by                   #+#    #+#             */
/*   Updated: 2016/03/10 00:27:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		mouse_hook_mandelbrot(int btn, int x, int y, t_hook_info *info)
{
	(void)btn;
	info->mouse.button = 1;
	info->mouse.pos.x += ((x * 2 - W_WIDTH) / 2);
	info->mouse.pos.y += ((y * 2 - W_HEIGHT) / 2);
	info->mouse.pos.x *= FACTOR_ZOOM;
	info->mouse.pos.y *= FACTOR_ZOOM;
	info->keycode = 24;
	ft_mandelbrot(info);
	info->mouse.button = 0;
	return (0);
}

int		key_hook_mandelbrot(int keycode, t_hook_info *info)
{
	info->keycode = keycode;
	if (keycode == 53)
	{
		if (info->n == 1)
			ft_exit_all_fractol(info);
		else
			ft_exit_one_fractol(info);
	}
	else
		ft_mandelbrot(info);
	return (1);
}

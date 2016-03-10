/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:00:38 by                   #+#    #+#             */
/*   Updated: 2016/03/10 12:02:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		mouse_hook_mandelbrot(int btn, int x, int y, t_hook_info *info)
{
	info->mouse.button = btn;
	info->mouse.pos.x = x;
	info->mouse.pos.y = y;
	if (btn == 5 || btn == 1)
		info->keycode = 24;
	else if (btn == 4 || btn == 2)
		info->keycode = 27;
	ft_mandelbrot(info);
	info->mouse.button = -1;
	info->keycode = -1;
	return (0);
}

/*
 * btn == 5 scroll +
 * btn == 4 scroll -
*/

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

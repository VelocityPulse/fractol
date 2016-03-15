/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliabs_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:29:41 by                   #+#    #+#             */
/*   Updated: 2016/03/15 17:20:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_start_juliabs_hook(t_hook_info *info)
{
	t_mlx	*mlx;

	mlx = info->current_mlx;
	mlx_hook(mlx->p_win, KeyPress, KeyPressMask, key_hook_juliabs, info);
	mlx_hook(mlx->p_win, MotionNotify, KeyPressMask, mouse_hook_juliabs, info);
	mlx_hook(mlx->p_win, ButtonPress, KeyPressMask, click_hook_juliabs, info);
}

int		mouse_hook_juliabs(int x, int y, t_hook_info *info)
{
	if (x >= 0 && x <= W_WIDTH && y >= 0 && y <= W_HEIGHT &&
			info->mouse.block == 0)
	{
		info->mouse.pos.x = (y * 2 - W_WIDTH * 1.5);
		info->mouse.pos.y = (y * 2 - W_HEIGHT * 1.5);
		ft_juliabs(info);
	}
	info->mouse.button = -1;
	info->keycode = -1;
	return (0);
}

int		click_hook_juliabs(int btn, int x, int y, t_hook_info *info)
{
	if (btn == 1)
	{
		if (info->mouse.block == 1)
			info->mouse.block = 0;
		else
			info->mouse.block = 1;
	}
	(void)x;
	(void)y;
	return (0);
}

int		key_hook_juliabs(int keycode, t_hook_info *info)
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
		ft_juliabs(info);
	return (0);
}

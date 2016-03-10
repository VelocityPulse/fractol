/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 22:05:08 by                   #+#    #+#             */
/*   Updated: 2016/03/10 23:39:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_start_julia_hook(t_hook_info *info)
{
	t_mlx	*mlx;

	mlx = info->current_mlx;
	mlx_hook(mlx->p_win, KeyPress, KeyPressMask, key_hook_julia, info);
	mlx_mouse_hook(mlx->p_win, mouse_hook_julia, info);
}

int		mouse_hook_julia(int btn, int x, int y, t_hook_info *info)
{
	info->mouse.button = btn;
	info->mouse.pos = ft_make_ptll(x, y);
	if (btn == 5 || btn == 1)
		info->keycode = 24;
	else if (btn == 4 || btn == 2)
		info->keycode = 27;
	ft_julia(info);
	info->mouse.button = -1;
	info->keycode = -1;
	return (0);
}

int		key_hook_julia(int keycode, t_hook_info *info)
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
		ft_julia(info);
	return (1);
}

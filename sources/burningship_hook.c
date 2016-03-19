/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:19:59 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/19 12:49:49 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_start_burningship_hook(t_hook_info *info)
{
	t_mlx	*mlx;

	mlx = info->current_mlx;
	mlx_hook(mlx->p_win, KeyPress, KeyPressMask, key_hook_burningship, info);
	mlx_mouse_hook(mlx->p_win, mouse_hook_burningship, info);
}

int		mouse_hook_burningship(int b, int x, int y, t_hook_info *info)
{
	info->mouse.button = b;
	info->mouse.pos = ft_make_ptll(x, y);
	if (b == 5 || b == 1)
		info->keycode = 24;
	else if (b == 4 || b == 2)
		info->keycode = 27;
	ft_burningship(info);
	info->mouse.button = -1;
	info->keycode = -1;
	return (0);
}

/*
** btn == 5 scroll +
** btn == 4 scroll -
*/

int		key_hook_burningship(int keycode, t_hook_info *info)
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
		ft_burningship(info);
	return (0);
}

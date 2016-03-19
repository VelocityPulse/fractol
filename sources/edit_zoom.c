/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:20:49 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/19 12:54:35 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_calc_pos(t_hook_info *info, t_ptll mouse_pos)
{
	info->f->pos.x += (mouse_pos.x * 2 - W_WIDTH) / 2;
	info->f->pos.y += (mouse_pos.y * 2 - W_HEIGHT) / 2;
}

void	ft_edit_zoom(t_hook_info *info)
{
	if (info->keycode == 24)
	{
		if (info->mouse.button == 5 || info->mouse.button == 1)
			ft_calc_pos(info, info->mouse.pos);
		info->f->pos.x *= FACTOR_ZOOM;
		info->f->pos.y *= FACTOR_ZOOM;
		info->f->zoom *= FACTOR_ZOOM;
		info->f->i_max *= FACTOR_ITER;
		info->f->nb_zoom++;
	}
	else if (info->keycode == 27)
	{
		if (!info->f->nb_zoom)
		{
			info->f->pos = ft_make_ptll(0, 0);
			return ;
		}
		if (info->mouse.button == 4 || info->mouse.button == 2)
			ft_calc_pos(info, info->mouse.pos);
		info->f->pos.x /= FACTOR_ZOOM;
		info->f->pos.y /= FACTOR_ZOOM;
		info->f->zoom /= FACTOR_ZOOM;
		info->f->i_max /= FACTOR_ITER;
		info->f->nb_zoom--;
	}
}

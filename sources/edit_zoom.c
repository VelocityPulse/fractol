/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:31:10 by                   #+#    #+#             */
/*   Updated: 2016/03/10 11:29:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_edit_pos(t_hook_info *info, t_ptll mouse_pos)
{
	info->f->pos.x += (mouse_pos.x * 2 - W_WIDTH) / 2;
	info->f->pos.y += (mouse_pos.y * 2 - W_HEIGHT) / 2;
}

void			ft_edit_zoom(double *zoom, int *i_max, t_hook_info *info)
{
	if (info->keycode == 24) // +
	{
		if (info->mouse.button == 5 || info->mouse.button == 1)
			ft_edit_pos(info, info->mouse.pos);
		info->f->pos.x *= FACTOR_ZOOM;
		info->f->pos.y *= FACTOR_ZOOM;
		*zoom *= FACTOR_ZOOM;
		*i_max *= FACTOR_ZOOM - 0.38;
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
			ft_edit_pos(info, info->mouse.pos);
		info->f->pos.x /= FACTOR_ZOOM;
		info->f->pos.y /= FACTOR_ZOOM;
		*zoom /= FACTOR_ZOOM;
		*i_max /= FACTOR_ZOOM - 0.38;
		info->f->nb_zoom--;
	}
}

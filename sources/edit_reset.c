/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:07:39 by                   #+#    #+#             */
/*   Updated: 2016/03/12 12:39:35 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_edit_reset_mandelbrot(t_hook_info *info)
{
	if (info->keycode == 49)
	{
		info->f->zoom = 400;
		info->f->i_max = 70;
		info->f->pos = ft_make_ptll(0, 0);
		info->f->color_value1 = 21;
		info->f->color_value2 = 21;
		ft_calc_color(info);
	}
}

void	ft_edit_reset_julia(t_hook_info *info)
{
	if (info->keycode == 49)
	{
		info->f->zoom = 337;
		info->f->i_max = 60;
		info->f->pos = ft_make_ptll(0, 0);
		info->mouse.pos = ft_make_ptll(0, 0);
		info->f->color_value1 = 15;
		info->f->color_value2 = 21;
		ft_calc_color(info);
	}
}

void	ft_edit_reset_buddhabrot(t_hook_info *info)
{
	if (info->keycode == 49)
	{
	info->f->zoom = 100;
	info->f->i_max = 100;
	info->f->pos = ft_make_ptll(0, 0);
	info->mouse.pos = ft_make_ptll(0, 0);
	info->f->color_value1 = 27;
	info->f->color_value2 = 27;
	ft_calc_color(info);
	}
}

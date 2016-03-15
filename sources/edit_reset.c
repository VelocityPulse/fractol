/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:07:39 by                   #+#    #+#             */
/*   Updated: 2016/03/15 17:44:13 by                  ###   ########.fr       */
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

void	ft_edit_reset_burningship(t_hook_info *info)
{
	if (info->keycode == 49)
	{
		info->f->zoom = 300;
		info->f->i_max = 60;
		info->f->pos = ft_make_ptll(0, 0);
		info->mouse.pos = ft_make_ptll(0, 0);
		info->f->color_value1 = 0;
		info->f->color_value2 = 6;
		ft_calc_color(info);
	}
}

void	ft_edit_reset_juliabs(t_hook_info *info)
{
	if (info->keycode == 49)
	{
		info->f->zoom = 300;
		info->f->i_max = 70;
		info->f->pos = ft_make_ptll(0, 0);
		info->mouse.pos = ft_make_ptll(0, 0);
		info->f->color_value1 = 6;
		info->f->color_value2 = 0;
		ft_calc_color(info);
	}
}

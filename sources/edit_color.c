/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:18:32 by                   #+#    #+#             */
/*   Updated: 2016/03/10 14:05:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_edit_color1(t_hook_info *info)
{
	if (info->keycode == 25)
	{
		if (info->f->color_value1 > 0)
			info->f->color_value1--;
		else
			info->f->color_value1 = COLOR_INTERVAL;
	}
	else
	{
		if (info->f->color_value1 < 30)
			info->f->color_value1++;
		else
			info->f->color_value1 = 0;
	}
	ft_calc_color1(info);
}

static void			ft_edit_color2(t_hook_info *info)
{
	if (info->keycode == 31)
	{
		if (info->f->color_value1 > 0)
			info->f->color_value1--;
		else
			info->f->color_value1 = COLOR_INTERVAL;
	}
	else
	{
		if (info->f->color_value1 < COLOR_INTERVAL)
			info->f->color_value1++;
		else
			info->f->color_value1 = 0;
	}
	ft_calc_color2(info);
}

void			ft_edit_color(t_hook_info *info)
{
	if (info->keycode == 25 || info->keycode == 29)
		ft_edit_color1(info);
	else if (info->keycode == 31 || info->keycode == 35)
		ft_edit_color2(info);
}

/*
 * 25 = (
 * 29 = )
 * 31 = o
 * 35 = p
*/

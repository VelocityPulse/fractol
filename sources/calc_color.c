/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:19:47 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/19 12:49:17 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void		ft_calc_color1(t_hook_info *info)
{
	int			x;
	t_rgb		c;

	c = info->f->rgb_max1;
	x = (1530 / COLOR_INTERVAL) * info->f->color_value1;
	if (x >= 0 && x < 255)
		c = ft_get_rgb(ft_get_hexa_rgb(255, x, 0));
	else if (x >= 255 && x < 510)
		c = ft_get_rgb(ft_get_hexa_rgb(510 - x, 255, 0));
	else if (x >= 510 && x < 765)
		c = ft_get_rgb(ft_get_hexa_rgb(0, 255, x - 510));
	else if (x >= 765 && x < 1020)
		c = ft_get_rgb(ft_get_hexa_rgb(0, 1020 - x, 255));
	else if (x >= 1020 && x < 1275)
		c = ft_get_rgb(ft_get_hexa_rgb(x - 1020, 0, 255));
	else if (x >= 1275 && x < 1530)
		c = ft_get_rgb(ft_get_hexa_rgb(255, 0, 1530 - x));
	info->f->rgb_max1 = c;
}

void		ft_calc_color2(t_hook_info *info)
{
	info->f->rgb_max2.r = (255 / COLOR_INTERVAL) * info->f->color_value2;
	info->f->rgb_max2.g = (255 / COLOR_INTERVAL) * info->f->color_value2;
	info->f->rgb_max2.b = (255 / COLOR_INTERVAL) * info->f->color_value2;
}

void		ft_calc_color(t_hook_info *info)
{
	ft_calc_color1(info);
	ft_calc_color2(info);
}

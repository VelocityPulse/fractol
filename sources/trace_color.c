/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:21:38 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/19 12:21:40 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_trace_color(t_hook_info *info, t_pt px)
{
	t_rgb	c;
	int		i;
	int		im;
	int		hexa;

	c = info->f->rgb_max1;
	i = info->f->i;
	im = info->f->i_max;
	if (info->f->i >= info->f->i_max)
		ft_draw_pixel(info->current_mlx, ft_get_hexa(info->f->rgb_max2), px);
	else
	{
		hexa = ft_get_hexa_rgb(i * c.r / im, i * c.g / im, i * c.b / im);
		ft_draw_pixel(info->current_mlx, hexa, px);
	}
}

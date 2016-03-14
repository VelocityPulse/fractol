/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_buddhabrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 17:07:12 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/14 16:06:37 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static int	ft_tab_max_buddhabrot(t_fractal *f)
{
	int		tab_max;
	t_pt	p;

	tab_max = 0;
	p.x = -1;
	while (++p.x < W_WIDTH)
	{
		p.y = -1;
		while (++p.y < W_HEIGHT)
		{
			if (f->tab[p.x + p.y] > tab_max)
				tab_max = f->tab[p.x + p.y];
		}
	}
	return (tab_max == 0 ? 1 : tab_max);
}

void		ft_trace_buddhabrot(t_hook_info *info)
{
	t_pt	p;
	int		tab_max;

	tab_max = ft_tab_max_buddhabrot(info->f);
	p.x = -1;
	while (++p.x < W_WIDTH)
	{
		p.y = -1;
		while (++p.y < W_HEIGHT)
			ft_draw_pixel(info->current_mlx, ft_get_hexa_rgb(info->f->tab[p.x + p.y] * 255 / tab_max, 255, 255), p);
	}
}

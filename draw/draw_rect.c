/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:33:08 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:20:42 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_draw_rect(t_line line, t_mlx *mlx, int color)
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	x1 = line.start.x;
	y1 = line.start.y;
	x2 = line.end.x;
	y2 = line.end.y;
	ft_draw_line(ft_make_line(x1, y1, x2, y1), mlx, color);
	ft_draw_line(ft_make_line(x1, y1, x1, y2), mlx, color);
	ft_draw_line(ft_make_line(x2, y2, x1, y2), mlx, color);
	ft_draw_line(ft_make_line(x2, y2, x2, y1), mlx, color);
}

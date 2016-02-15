/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:17:34 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:25:09 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_draw_horizontal(t_line l, t_mlx *mlx, int variance, int color)
{
	while (l.start.x != l.end.x)
	{
		ft_draw_pixel(mlx, color, l.start);
		l.start.x += variance;
	}
}

void	ft_draw_vertical(t_line l, t_mlx *mlx, int variance, int color)
{
	while (l.start.y != l.end.y)
	{
		ft_draw_pixel(mlx, color, l.start);
		l.start.y += variance;
	}
}

void	ft_draw_bresenham(t_line l, t_mlx *mlx, t_pt variance, int color)
{
	int		err;

	if (l.dx < 0)
		l.dx = -l.dx;
	if (l.dy < 0)
		l.dy = -l.dy;
	err = -l.dx >> 1;
	while (l.start.x != l.end.x)
	{
		ft_draw_pixel(mlx, color, l.start);
		err += l.dy;
		while (err > 0)
		{
			ft_draw_pixel(mlx, color, l.start);
			err -= l.dx;
			l.start.y += variance.y;
		}
		l.start.x += variance.x;
	}
}

void	ft_draw_line(t_line l, t_mlx *mlx, int color)
{
	t_pt	variance;

	variance.x = (l.dx < 0) ? -1 : 1;
	variance.y = (l.dy < 0) ? -1 : 1;
	if (l.dx == 0 && l.dy == 0)
		ft_draw_pixel(mlx, color, l.start);
	else if (l.dy == 0)
		ft_draw_horizontal(l, mlx, variance.x, color);
	else if (l.dx == 0)
		ft_draw_vertical(l, mlx, variance.y, color);
	else
		ft_draw_bresenham(l, mlx, variance, color);
}

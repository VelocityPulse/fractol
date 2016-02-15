/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:32:21 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:31:28 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_draw_horizontal_c(t_line l, t_mlx *mlx, int var, t_dual_color c)
{
	t_rgb	d;
	int		n;
	int		x;

	if (l.dx < 0)
		l.dx = -l.dx;
	n = l.dx;
	x = 0;
	while (l.start.x != l.end.x)
	{
		d = ft_find_color_gradient(c, n, x++);
		ft_draw_pixel(mlx, ft_get_hexa(d), l.start);
		l.start.x += var;
	}
}

void	ft_draw_vertical_c(t_line l, t_mlx *mlx, int var, t_dual_color c)
{
	t_rgb	d;
	int		n;
	int		x;

	if (l.dy < 0)
		l.dy = -l.dy;
	n = l.dy;
	x = 0;
	while (l.start.y != l.end.y)
	{
		d = ft_find_color_gradient(c, n, x++);
		ft_draw_pixel(mlx, ft_get_hexa(d), l.start);
		l.start.y += var;
	}
}

void	ft_draw_bresenham_c(t_line l, t_mlx *mlx, t_pt var, t_dual_color c)
{
	t_rgb	d;
	int		err;
	int		n;
	int		x;

	if (l.dx < 0 && !(x = 0))
		l.dx = -l.dx;
	if (l.dy < 0)
		l.dy = -l.dy;
	n = l.dx + l.dy;
	err = -l.dx >> 1;
	while (l.start.x != l.end.x)
	{
		d = ft_find_color_gradient(c, n, x++);
		ft_draw_pixel(mlx, ft_get_hexa(d), l.start);
		err += l.dy;
		while (err > 0)
		{
			d = ft_find_color_gradient(c, n, x++);
			ft_draw_pixel(mlx, ft_get_hexa(d), l.start);
			err -= l.dx;
			l.start.y += var.y;
		}
		l.start.x += var.x;
	}
}

void	ft_draw_color_line(t_line l, t_mlx *mlx, int c1, int c2)
{
	t_pt			variance;
	t_dual_color	c;

	c.c1 = ft_get_rgb(c1);
	c.c2 = ft_get_rgb(c2);
	variance.x = (l.dx < 0) ? -1 : 1;
	variance.y = (l.dy < 0) ? -1 : 1;
	if (l.dx == 0 && l.dy == 0)
		ft_draw_pixel(mlx, c1, l.start);
	else if (l.dy == 0)
		ft_draw_horizontal_c(l, mlx, variance.x, c);
	else if (l.dx == 0)
		ft_draw_vertical_c(l, mlx, variance.y, c);
	else
		ft_draw_bresenham_c(l, mlx, variance, c);
}

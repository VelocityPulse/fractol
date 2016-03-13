/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 16:46:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/13 17:47:50 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_reset_buddhabrot_tab(t_fractal *f, int m)
{
	int		x;

	x = 0;
	while (++x < W_WIDTH)
		ft_bzero(&f->iter[x], W_HEIGHT);
	if (m != 2)
		return ;
	x = 0;
	while (++x < W_WIDTH)
		ft_bzero(&f->tab[x], W_HEIGHT);
}

void	ft_buddhabrot_iter(t_fractal *f, t_ptll pos, t_pt px, t_pt i)
{
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		tmp;
	ft_reset_buddhabrot_tab(f, 1);
	cr = (long double)(px.x + f->min.x + pos.x) / f->zoom + f->x1;
	ci = (long double)(px.y + f->min.y + pos.y) / f->zoom + f->y1;
	zr = 0;
	zi = 0;

	while ((zr * zr) + (zi * zi) < 4 && ++i.x < i.y)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zi * tmp + ci;
		f->iter[(int)((zr - f->x1) * f->zoom)][(int)((zi - f->y1) * f->zoom)]++;
	}
	f->i = i.x;
}

void	ft_buddhabrot_add_iter(t_fractal *f)
{
	int		x;
	int		y;

	if (f-> i != f->i_max)
	{
		x = 0;
		while (++x < W_WIDTH)
		{
			y = 0;
			while (++y < W_HEIGHT)
			{
				if (f->iter[x][y])
					f->tab[x][y]++;
			}
		}
	}
}

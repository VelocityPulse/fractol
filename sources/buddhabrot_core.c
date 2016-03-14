/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 16:46:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/14 17:08:05 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_reset_buddhabrot_tab(t_fractal *f, int m)
{
	int		x;

	x = -1;
	while (++x < W_WIDTH)
		ft_bzero(&f->iter[x], W_HEIGHT);
	if (m != 2)
		return ;
	x = -1;
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
	int			tab[W_WIDTH * W_HEIGHT];
	int a;
	int b;

	(void)tab;
	cr = (long double)(px.x + f->min.x + pos.x) / f->zoom + f->x1;
	ci = (long double)(px.y + f->min.y + pos.y) / f->zoom + f->y1;
	zr = 0;
	zi = 0;
	while ((zr * zr) + (zi * zi) < 4 && ++i.x < i.y)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zi * tmp + ci;
		a = ((zr - f->x1 + 2) * f->zoom);
		b = ((zi - f->y1 + 2) * f->zoom);
		//a = a < 0 ? -a : a;
		//b = b < 0 ? -b : b;
		++tab[a + b];
	}
	f->i = i.x;
	ft_buddhabrot_add_iter(f, tab);
}

void	ft_buddhabrot_add_iter(t_fractal *f, int tab[])
{
	int		i;

	if (f->i != f->i_max)
	{
		i = -1;
		while (++i < W_WIDTH * W_HEIGHT)
		{
				if (tab[i])
					++f->tab[i];
		}
	}
}

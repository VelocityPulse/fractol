/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:19:20 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/19 12:22:32 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_burningship_iter(t_fractal *f, t_ptll pos, t_pt px, t_pt i)
{
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;

	c_r = (long double)(px.x + f->min.x + pos.x) / f->zoom + f->x1;
	c_i = (long double)(px.y + f->min.y + pos.y) / f->zoom + f->y1;
	z_r = 0;
	z_i = 0;
	while ((z_r * z_r) + (z_i * z_i) < 4 && ++i.x < i.y)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * fabs(z_i * tmp) + c_i;
	}
	f->i = i.x;
}

/*
** i.x = i
** i.y = i_max
*/

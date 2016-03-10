/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 22:17:35 by                   #+#    #+#             */
/*   Updated: 2016/03/10 23:20:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_julia_iter(t_fractal *f, t_ptll pos, t_pt px, t_pt i)
{
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;

	c_r = 0.285;
	c_i = 0.01;
	z_r = (long double)(px.x + f->min.x + pos.x) / f->zoom + f->x1;
	z_i = (long double)(px.y + f->min.y + pos.y) / f->zoom + f->y1;
	while ((z_r * z_r) + (z_i * z_i) < 4 && ++i.x < i.y)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
	}
	f->i = i.x;
}

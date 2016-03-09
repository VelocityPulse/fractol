/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:08:55 by                   #+#    #+#             */
/*   Updated: 2016/03/09 14:42:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_mandelbrot_frame_init(t_fractal *f)
{
	int		image_x;
	int		image_y;
	
	image_x = (f->x2 - f->x1) * f->zoom;
	image_y = (f->y2 - f->y1) * f->zoom;
	f->max.x = image_x - ((image_x - W_WIDTH) / 2);
	f->max.y = image_y - ((image_y - W_HEIGHT) / 2);
	f->min.x = (image_x - W_WIDTH) / 2;
	f->min.y = (image_y - W_HEIGHT) / 2;
}

void	ft_mandelbrot_iter(t_fractal *f, t_ptll pos, t_pt px, t_pt i)
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
		z_i = 2 * z_i * tmp + c_i;
	}
	f->i = i.x;
}

/*
 * i.x = i
 * i.y = i_max
*/

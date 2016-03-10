/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:04:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/10 12:16:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_fractal		*ft_init_mandelbrot_fractal(void)
{
	t_fractal	*f;

	f = (t_fractal *)ft_memalloc(sizeof(t_fractal));
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->min.x = 0;
	f->min.y = 0;
	f->max.x = 0;
	f->max.y = 0;
	f->zoom = 400;
	f->i_max = 60;
	f->nb_zoom = 0;
	return (f);
}

void			ft_mandelbrot(t_hook_info *info)
{
	t_fractal	*f;
	t_pt		p;
	t_ptll		index;

	f = info->f;
	ft_reset_image(info->current_mlx, 0);
	p = ft_make_pt(0, 0);
	ft_edit_reset(info);
	ft_edit_zoom(info);
	ft_edit_imax(info);
	ft_mandelbrot_frame_init(f);
	p.x = 0;
	index.x = f->min.x - 1;
	while (++index.x < f->max.x)
	{
		p.y = 0;
		index.y = f->min.y - 1;
		while (++index.y < f->max.y)
		{
			ft_mandelbrot_iter(f, info->f->pos, p, ft_make_pt(-1, f->i_max));
			if (f->i >= f->i_max)
				ft_draw_pixel(info->current_mlx, 0x555555, p);
			else
				ft_draw_pixel(info->current_mlx, ft_get_hexa_rgb(0, f->i * 255 / f->i_max, f->i * 255 / f->i_max), p);
			p.y++;
		}
		p.x++;
	}
	ft_draw_pixel(info->current_mlx, 0x00ffff, ft_make_pt(W_WIDTH / 2, W_HEIGHT / 2));
	ft_flush_image(info->current_mlx);
}

t_list_mlx		*ft_add_mandelbrot(int n, t_list_mlx *begin)
{
	t_hook_info		*info;
	static int		i = 1;
	char			*str1;
	char			*str2;

	info = (t_hook_info *)ft_memalloc(sizeof(t_hook_info));
	info->n = n;
	info->f = ft_init_mandelbrot_fractal();
	str2 = ft_itoa(i);
	if (n == 1)
		str1 = ft_strjoin("main : fract'ol Mandelbrot ", str2);
	else
		str1 = ft_strjoin("fract'ol Mandelbrot ", str2);
	info->current_mlx = NULL;
	info->current_mlx = ft_mlx_init(W_WIDTH, W_HEIGHT, info->current_mlx, str1);
	begin = ft_add_list_mlx(begin, info, n);
	info->l_mlx = begin;
	mlx_key_hook(info->current_mlx->p_win, key_hook_mandelbrot, info);
	mlx_mouse_hook(info->current_mlx->p_win, mouse_hook_mandelbrot, info);
	if (n > 1)
		ft_mandelbrot(info);
	i++;
	ft_memdel((void **)&str1);
	ft_memdel((void **)&str2);
	ft_mandelbrot(info);
	return (begin);
}

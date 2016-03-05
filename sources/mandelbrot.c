/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:04:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/05 20:55:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		mouse_hook_mandelbrot(int button, int x, int y, t_hook_info *info)
{
	info->mouse.button = 1;
	info->mouse.px += ((x * 2 - W_WIDTH) / 2);
	info->mouse.py += ((y * 2 - W_HEIGHT) / 2);
	info->mouse.px *= FACTOR_ZOOM;
	info->mouse.py *= FACTOR_ZOOM;
	info->mouse.x += x;
	info->mouse.y += y;
	info->keycode = 24;
	ft_mandelbrot(info);
	info->mouse.button = 0;
	button = 0;
	return (1);
}

int		key_hook_mandelbrot(int keycode, t_hook_info *info)
{
	info->keycode = keycode;
	if (keycode == 53)
	{
		if (info->n == 1)
			ft_exit_all_fractol(info);
		else
			ft_exit_one_fractol(info);
	}
	else
		ft_mandelbrot(info);
	return (1);
}

void		ft_edit_reset(double *zoom, double *i_max, t_hook_info *info)
{
	if (info->keycode == 49)
	{
		*zoom = 400;
		*i_max = 70;
		info->mouse.px = 0;
		info->mouse.py = 0;
		info->mouse.x = 0;
		info->mouse.y = 0;
		info->mouse.nb_zoom = 0;
	}
}

void		ft_edit_zoom(double *zoom, double *i_max, t_hook_info *info)
{
	static t_pt		last_points;

	if (info->keycode == 24) // +
	{
		if (info->mouse.button == 0)
		{
			info->mouse.px *= FACTOR_ZOOM;
			info->mouse.py *= FACTOR_ZOOM;
			info->mouse.x *= FACTOR_ZOOM;
			info->mouse.y *= FACTOR_ZOOM;
		}
		*zoom *= FACTOR_ZOOM;
		*i_max *= FACTOR_ZOOM - 0.38;
		info->mouse.nb_zoom++;
		last_points = ft_make_pt(info->mouse.px, info->mouse.py);
	}
	else if (info->keycode == 27) // -
	{
		if ((info->mouse.nb_zoom > 0) && ((last_points.x < 0 && info->mouse.px < 0) ||
		(last_points.x > 0 && info->mouse.px > 0)) && ((last_points.y < 0 && info->mouse.py < 0) ||
		(last_points.y > 0 && info->mouse.py > 0)))
		{
			info->mouse.px /= FACTOR_ZOOM;
			info->mouse.py /= FACTOR_ZOOM;
			info->mouse.px -= ((info->mouse.x / info->mouse.nb_zoom) * 2 - W_WIDTH) / 2;
			info->mouse.py -= ((info->mouse.y / info->mouse.nb_zoom) * 2 - W_HEIGHT) / 2;
			info->mouse.x -= info->mouse.x / info->mouse.nb_zoom;
			info->mouse.y -= info->mouse.y / info->mouse.nb_zoom;
			*zoom /= FACTOR_ZOOM;
			*i_max /= FACTOR_ZOOM - 0.38;
			info->mouse.nb_zoom--;
		}
		else
		{
			info->mouse.px = 0;
			info->mouse.py = 0;
		}
	}
	printf("nb_zoom : %d\n", info->mouse.nb_zoom);
}

void		ft_mandelbrot(t_hook_info *info)
{
	static double	x1 = -2.1;
	static double	x2 = 0.6;
	static double	y1 = -1.2;
	static double	y2 = 1.2;

	static double	zoom = 400;

	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;
	static double	i_max = 70;
	double	tmp;
	t_pt	p;
	t_pt	min;
	t_pt	max;
	t_pt	index;

	ft_reset_image(info->current_mlx, 0);
	p = ft_make_pt(0, 0);
	max = ft_make_pt(0, 0);
	min = ft_make_pt(0, 0);
	ft_edit_zoom(&zoom, &i_max, info);
	ft_edit_reset(&zoom, &i_max, info);

	printf("mouse x : %ld\nmouse y : %ld\n\n", info->mouse.px, info->mouse.py);

	int		image_x = (x2 - x1) * zoom;
	int		image_y = (y2 - y1) * zoom;

	if (image_y > W_HEIGHT)
	{
		max.y = image_y - ((image_y - W_HEIGHT) / 2);
		max.x = image_x - ((image_x - W_WIDTH) / 2);
		min.y = (image_y - W_HEIGHT) / 2;
		min.x = (image_x - W_WIDTH) / 2;
	}
	else
	{
		max.y = W_HEIGHT;
		max.x = W_WIDTH;
		min.y = 0;
		min.x = 0;
	}
	if (image_x < W_WIDTH)
		p.x = min.x;
	else
		p.x = 0;
	index.x = min.x - 1;
	while (++index.x < max.x)
	{
		if (image_y < W_HEIGHT)
			p.y = min.y;
		else
			p.y = 0;
		index.y = min.y - 1;
		while (++index.y < max.y)
		{
			if (image_x < W_WIDTH)
				c_r = (double)(p.x - min.x + info->mouse.px) / zoom + x1;
			else
				c_r = (double)(p.x + min.x + info->mouse.px) / zoom + x1;
			if (image_y < W_HEIGHT)
				c_i = (double)(p.y - min.y + info->mouse.py) / zoom + y1;
			else
				c_i = (double)(p.y + min.y + info->mouse.py) / zoom + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while ((z_r * z_r) + (z_i * z_i) < 4 && i < i_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i >= i_max)
			{
				if (image_x > W_WIDTH)
					ft_draw_pixel(info->current_mlx, 0x555555, p);
				else
					ft_draw_pixel(info->current_mlx, 0x555555, p);
			}
			else
			{
				if (image_y > W_HEIGHT)
					ft_draw_pixel(info->current_mlx, ft_get_hexa_rgb(0, i * 255 / i_max, i * 255 / i_max), p);
				else
					ft_draw_pixel(info->current_mlx, ft_get_hexa_rgb(0, i * 255 / i_max, i * 255 / i_max), p);
			}
			p.y++;
		}
		p.x++;
	}
	ft_draw_pixel(info->current_mlx, 0x00ffff, ft_make_pt(W_WIDTH / 2, W_HEIGHT / 2));
	mlx_do_sync(info->current_mlx);
	ft_flush_image(info->current_mlx);
}

t_fractol	*ft_add_mandelbrot(int n, t_fractol *begin)
{
	t_hook_info		*info;
	static int		i = 1;
	char			*str1;
	char			*str2;

	info = (t_hook_info *)ft_memalloc(sizeof(t_hook_info));
	info->n = n;
	info->keycode = -1;
	info->mouse.px = 0;
	info->mouse.py = 0;
	info->mouse.button = 0;
	info->mouse.nb_zoom = 0;
	str2 = ft_itoa(i);
	if (n == 1)
		str1 = ft_strjoin("main : fract'ol Mandelbrot ", str2);
	else
		str1 = ft_strjoin("fract'ol Mandelbrot ", str2);
	info->current_mlx = NULL;
	info->current_mlx = ft_mlx_init(W_WIDTH, W_HEIGHT, info->current_mlx, str1);
	begin = ft_add_list_fractol(begin, info->current_mlx, n);
	info->l_fractol = begin;
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

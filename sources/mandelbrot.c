/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:04:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/07 17:30:30 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int				mouse_hook_mandelbrot(int button, int x, int y, t_hook_info *info)
{
	mlx_do_sync(info->current_mlx);
	info->mouse.button = 1;
	info->mouse.px += ((x * 2 - W_WIDTH) / 2);
	info->mouse.py += ((y * 2 - W_HEIGHT) / 2);
	info->mouse.px *= FACTOR_ZOOM;
	info->mouse.py *= FACTOR_ZOOM;
	info->keycode = 24;
	ft_mandelbrot(info);
	info->mouse.button = 0;
	(void)button;
	return (1);
}

int				key_hook_mandelbrot(int keycode, t_hook_info *info)
{
	info->keycode = keycode;
	mlx_do_sync(info->current_mlx);

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

void			ft_edit_reset(double *zoom, double *i_max, t_hook_info *info)
{
	if (info->keycode == 49)
	{
		*zoom = 400;
		*i_max = 70;
		info->mouse.px = 0;
		info->mouse.py = 0;
		info->mouse.nb_zoom = 0;
	}
}

void			ft_edit_zoom(double *zoom, double *i_max, t_hook_info *info)
{
	if (info->keycode == 24) // +
	{
		if (info->mouse.button == 0)
		{
			info->mouse.px *= FACTOR_ZOOM;
			info->mouse.py *= FACTOR_ZOOM;
		}
		*zoom *= FACTOR_ZOOM;
		*i_max *= FACTOR_ZOOM - 0.38;
		info->mouse.nb_zoom++;
	}
	else if (info->keycode == 27) // -
	{
		if (info->mouse.nb_zoom)
		{
			info->mouse.px /= FACTOR_ZOOM;
			info->mouse.py /= FACTOR_ZOOM;
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
}

t_fractal		*ft_init_mandelbrot_fractal(void)
{
	t_fractal	*f;

	f = (t_fractal *)ft_memalloc(sizeof(t_fractal));
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->zoom = 400;
	f->i_max = 60;
	return (f);
}

void			ft_mandelbrot(t_hook_info *info)
{
	t_fractal	*f;
	t_pt		p;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	t_pt		min;
	t_pt		max;
	t_pt		index;
	int			i;
	double		i_max;
	double		zoom;


	f = info->f;
	ft_reset_image(info->current_mlx, 0);
	p = ft_make_pt(0, 0);
	ft_edit_zoom(&f->zoom, &f->i_max, info);
	ft_edit_reset(&f->zoom, &f->i_max, info);
	i_max = f->i_max;
	zoom = f->zoom;
	printf("mouse x : %ld\nmouse y : %ld\n\n", info->mouse.px, info->mouse.py);

	f->image_x = (f->x2 - f->x1) * f->zoom;
	f->image_y = (f->y2 - f->y1) * f->zoom;

	max.y = f->image_y - ((f->image_y - W_HEIGHT) / 2);
	max.x = f->image_x - ((f->image_x - W_WIDTH) / 2);
	min.y = (f->image_y - W_HEIGHT) / 2;
	min.x = (f->image_x - W_WIDTH) / 2;
	p.x = 0;
	index.x = min.x - 1;
	while (++index.x < max.x)
	{
		p.y = 0;
		index.y = min.y - 1;
		while (++index.y < max.y)
		{
			c_r = (double)(p.x + min.x + info->mouse.px) / zoom + f->x1;
			c_i = (double)(p.y + min.y + info->mouse.py) / zoom + f->y1;
			z_r = 0;
			z_i = 0;
			i = -1;
			while ((z_r * z_r) + (z_i * z_i) < 4 && ++i < i_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
			}
			if (i >= f->i_max)
				ft_draw_pixel(info->current_mlx, 0x555555, p);
			else
				ft_draw_pixel(info->current_mlx, ft_get_hexa_rgb(0, i * 255 / i_max, i * 255 / i_max), p);
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
	info->keycode = -1;
	info->mouse.px = 0;
	info->mouse.py = 0;
	info->mouse.button = 0;
	info->mouse.nb_zoom = 0;
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

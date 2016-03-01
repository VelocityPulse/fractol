/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:04:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/01 13:11:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		mouse_hook_mandelbrot(int button, int x, int y, t_hook_info *info)
{
	button = 0;
	info->mouse.p = ft_make_pt(x, y);
	info->mouse.zoom.x = W_WIDTH - x * 2;
	info->mouse.zoom.y = W_HEIGHT - y * 2;
	info->keycode = 24;
	ft_mandelbrot(info);
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

void		ft_edit_zoom(double *x1, double *x2, double *y1, double *y2, 
		double *zoom, double *i_max, int keycode, t_hook_info *info)
{
	if (keycode == 24) // +
	{
		*zoom *= 1.5;
		*i_max *= 1.15;
	}
	else if (keycode == 27) // -
	{
		*zoom /= 1.5;
		*i_max /= 1.05;
		info->mouse.zoom.x /= 2;
		info->mouse.zoom.y /= 2;
	}
	(void)i_max;
	(void)x1;
	(void)y1;
	(void)x2;
	(void)y2;
	//	printf("i_max : %f\n", *i_max);
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
	static double	i_max = 100;
	double	tmp;
	t_pt	p;
	t_pt	min;
	t_pt	max;
	t_pt	index;

	long int	cpt = 0;
	long int	cpt2 = 0;

	ft_reset_image(info->current_mlx, 0);
	p = ft_make_pt(0, 0);
	max = ft_make_pt(0, 0);
	min = ft_make_pt(0, 0);
	ft_edit_zoom(&x1, &x2, &y1, &y2, &zoom, &i_max, info->keycode, info);

	printf("mouse x : %d\nmouse y : %d\n", info->mouse.p.x, info->mouse.p.y);

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
		max.y = W_HEIGHT / 2 + image_y / 2;
		max.x = W_WIDTH / 2 + image_x / 2;
		min.y = W_HEIGHT / 2 - image_y / 2;
		min.x = W_WIDTH / 2 - image_x / 2;
	}
	printf("dif max.x et min.x : %d\n", max.x - min.x);
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
				c_r = (double)(p.x - min.x + info->mouse.p.x) / zoom + x1;
			else
				c_r = (double)(p.x + min.x + info->mouse.p.x)/ zoom + x1;
			if (image_y < W_HEIGHT)
				c_i = (double)(p.y - min.y + info->mouse.p.y) / zoom + y1;
			else
				c_i = (double)(p.y + min.y + info->mouse.p.y)  / zoom + y1;
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
					ft_draw_pixel(info->current_mlx, 0x000000, p);
				else
					ft_draw_pixel(info->current_mlx, 0x000000, p);
			}
			else
			{
				if (image_y > W_HEIGHT)
					ft_draw_pixel(info->current_mlx, ft_get_hexa_rgb(0, i * 255 / i_max, 0), p);
				else
					ft_draw_pixel(info->current_mlx, ft_get_hexa_rgb(0, i * 255 / i_max, 0), p);
			}
			cpt++;
			p.y++;
		}
		p.x++;
		cpt2++;
	}
	printf("y : %d\n", p.y);
	printf("x : %d\n", p.x);
	ft_draw_pixel(info->current_mlx, 0xffffff, ft_make_pt(W_WIDTH / 2, W_HEIGHT / 2));
	printf("%ld %ld\n\n", cpt, cpt2);
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
	info->mouse.p = ft_make_pt(0, 0);
	info->mouse.button = 0;
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

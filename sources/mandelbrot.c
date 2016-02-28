/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:04:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/28 22:39:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

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
		double *zoom_x, double *zoom_y, double *i_max, int keycode)
{
	if (keycode == 24) // +
	{
		*zoom_x *= 1.4;
		*zoom_y *= 1.4;
		*x1 /= 1.2;
		*x2 *= 1.2;
		*y1 /= 1.2;
		*y2 *= 1.2;
		*i_max *= 1.01;
	}
	else if (keycode == 27) // -
	{
		*zoom_x /= 1.4;
		*zoom_y /= 1.4;
		*x1 *= 1.2;
		*x2 /= 1.2;
		*y1 *= 1.2;
		*y2 /= 1.2;
		*i_max /= 1.01;
	}
	(void)i_max;
	(void)x2;
	(void)y2;
	(void)zoom_x;
	(void)zoom_y;
	printf("i_max : %f\n", *i_max);
}

void		ft_mandelbrot(t_hook_info *info)
{
	static double	x1 = -2.1;
	static double	x2 = 1.6;
	static double	y1 = -1.2;
	static double	y2 = 1.2;

	static double	zoom_x = 400;
	static double	zoom_y = 400;

	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;
	static double	i_max = 65;
	double	tmp;
	t_pt	p;

	long int	cpt = 0;


	ft_reset_image(info->current_mlx, 0xffffff);
	p = ft_make_pt(0, 0);
	ft_edit_zoom(&x1, &x2, &y1, &y2, &zoom_x, &zoom_y, &i_max, info->keycode);

	int		image_x = (x2 - x1) * zoom_x;
	int		image_y = (y2 - y1) * zoom_y;

//	printf("image_x = %d\nimage_y = %d\n\n", image_x, image_y);
	while (p.x < W_WIDTH && p.x < image_x)
	{
		p.y = 0;
		while (p.y < W_HEIGHT && p.y < image_y)
		{
			c_r = (double)p.x / zoom_x + x1;
			c_i = (double)p.y / zoom_y + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while ((z_r * z_r) + (z_i * z_i) < 4 && i < i_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
				cpt++;
			}
			if (i == i_max)
				ft_draw_pixel(info->current_mlx, 0x000000, p);
			else
				ft_draw_pixel(info->current_mlx, ft_get_hexa_rgb(0, i * 255 / i_max, 0), p);
			
			p.y++;
		}
		p.x++;
	}
	printf("%ld\n", cpt);
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
	if (n > 1)
		ft_mandelbrot(info);
	i++;
	ft_memdel((void **)&str1);
	ft_memdel((void **)&str2);
	ft_mandelbrot(info);
	return (begin);
}

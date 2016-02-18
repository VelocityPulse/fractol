/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:04:27 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/18 16:23:54 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		key_hook_julia(int keycode, t_hook_info *info)
{
//	ft_putstr("keyhook julia\n");
	if (keycode == 53)
	{
		if (info->n == 1)
			ft_exit_all_fractol(info);
		else
			ft_exit_one_fractol(info);
	}
	ft_julia(info);
	keycode = 1;
	return (1);
}

void		ft_julia(t_hook_info *info)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;
	double	tmp;
	t_pt	p;

	ft_reset_image(info->current_mlx, 0);
	p = ft_make_pt(0, 0);
	while (p.y < info->current_mlx->height)
	{
		while (p.x < info->current_mlx->width)
		{
			c_r = p.x;
			c_i = p.y;
			z_r = 0;
			z_i = 0;
			i = 0;
			while ((z_r * z_r) + (z_i * z_i) < 4 && i < 50)
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i += 1;
			}
			if (i == 50)
				ft_draw_pixel(info->current_mlx, 0x00ff00, p);
			p.x++;
		}
		p.y++;
	}
	YOLO
	ft_flush_image(info->current_mlx);
}

t_fractol	*ft_add_julia(int n, t_fractol *begin)
{
	t_hook_info		*info;
	static int		i = 1;
	char			*str1;
	char			*str2;

	info = (t_hook_info *)ft_memalloc(sizeof(t_hook_info));
	info->n = n;
	str2 = ft_itoa(i);
	if (n == 1)
		str1 = ft_strjoin("main : fract'ol Julia ", str2);
	else
		str1 = ft_strjoin("fract'ol Julia ", str2);
	info->current_mlx = NULL;
	info->current_mlx = ft_mlx_init(W_WIDTH, W_HEIGHT, info->current_mlx, str1);
	begin = ft_add_list_fractol(begin, info->current_mlx, n);
	info->l_fractol = begin;
	mlx_key_hook(info->current_mlx->p_win, key_hook_julia, info);
	i++;
	ft_memdel((void **)&str1);
	ft_memdel((void **)&str2);
	
	return (begin);
}

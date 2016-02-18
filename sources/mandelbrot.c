/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:04:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/18 17:13:31 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		key_hook_mandelbrot(int keycode, t_hook_info *info)
{
	//	ft_putstr("keyhook mandelbrot\n");
	if (keycode == 53)
	{
		if (info->n == 1)
			ft_exit_all_fractol(info);
		else
			ft_exit_one_fractol(info);
	}
	return (1);
}

t_fractol	*ft_add_mandelbrot(int n, t_fractol *begin)
{
	t_hook_info		*info;
	static int		i = 1;
	char			*str1;
	char			*str2;

	info = (t_hook_info *)ft_memalloc(sizeof(t_hook_info));
	info->n = n;
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
	i++;
	ft_memdel((void **)&str1);
	ft_memdel((void **)&str2);
	return (begin);
}

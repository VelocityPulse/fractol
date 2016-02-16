/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:04:27 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/16 16:16:22 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		key_hook_julia(int keycode, t_hook_info *info)
{
	ft_putstr("keyhook julia\n");
	keycode = 1;
	info = NULL;
	return (1);
}

t_mlx	*ft_julia(int n, t_fractol *begin)
{
	t_hook_info		*info;
	static int		i = 1;
	char			*str1;
	char			*str2;

	info = (t_hook_info *)ft_memalloc(sizeof(t_hook_info));
	info->n = n;
	info->begin = begin;
	str2 = ft_itoa(i);
	if (n == 1)
		str1 = ft_strjoin("main : fract'ol Julia ", str2);
	else
		str1 = ft_strjoin("fract'ol Julia ", str2);
	info->mlx = NULL;
	info->mlx = ft_mlx_init(W_WIDTH, W_HEIGHT, info->mlx, str1);
	mlx_key_hook(info->mlx->p_win, key_hook_julia, info);
	i++;
	ft_memdel((void **)&str1);
	ft_memdel((void **)&str2);
	return (info->mlx);
}

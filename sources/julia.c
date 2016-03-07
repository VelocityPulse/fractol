/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:04:27 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/07 14:34:02 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int			key_hook_julia(int keycode, t_hook_info *info)
{
	ft_putstr("keyhook julia\n");
	if (keycode == 53)
	{
		if (info->n == 1)
			ft_exit_all_fractol(info);
		else
			ft_exit_one_fractol(info);
	}
//	else
//		ft_julia(info);
	return (0);
}

t_list_mlx		*ft_add_julia(int n, t_list_mlx *begin)
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
	begin = ft_add_list_mlx(begin, info->current_mlx, n);
	info->l_mlx = begin;
	mlx_hook(info->current_mlx->p_win, KeyPress, KeyPressMask, key_hook_julia, info);
//	if (n > 1)
//		ft_julia(info);
	i++;
	ft_memdel((void **)&str1);
	ft_memdel((void **)&str2);
//	ft_julia(info);
	return (begin);
}

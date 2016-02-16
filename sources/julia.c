/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:04:27 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/16 12:37:48 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		key_hook_julia(int keycode, t_mlx *mlx)
{
	ft_putstr("keyhook julia\n");
	keycode = 1;
	mlx = NULL;
	return (1);
}

t_mlx	*ft_julia(int n)
{
	t_mlx			*mlx;
	static int		i = 1;
	char			*str1;
	char			*str2;

	str2 = ft_itoa(i);
	if (n == 1)
		str1 = ft_strjoin("main : fract'ol Julia ", str2);
	else
		str1 = ft_strjoin("fract'ol Julia ", str2);
	mlx = NULL;
	mlx = ft_mlx_init(300, 200, mlx, str1);
	mlx_key_hook(mlx->p_win, key_hook_julia, mlx);
	i++;
	ft_memdel((void **)&str1);
	ft_memdel((void **)&str2);
	return (mlx);
}
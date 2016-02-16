/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:04:51 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/16 12:36:44 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		key_hook_mandelbrot(int keycode, t_mlx *mlx)
{
	ft_putstr("keyhook mandelbrot\n");
	keycode = 1;
	mlx = NULL;
	return (1);
}

t_mlx	*ft_mandelbrot(int n)
{
	t_mlx			*mlx;
	static int		i = 1;
	char			*str1;
	char			*str2;

	str2 = ft_itoa(i);
	if (n == 1)
		str1 = ft_strjoin("main : fract'ol Mandelbrot ", str2);
	else
		str1 = ft_strjoin("fract'ol Mandelbrot ", str2);
	mlx = NULL;
	mlx = ft_mlx_init(300, 200, mlx, str1);
	mlx_key_hook(mlx->p_win, key_hook_mandelbrot, mlx);
	i++;
	ft_memdel((void **)&str1);
	ft_memdel((void **)&str2);
	return (mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:04:27 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 17:50:21 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		key_hook1(int keycode, t_mlx *mlx)
{
	ft_putstr("keyhook1\n");
	keycode = 1;
	mlx = NULL;
	return (1);
}

int		key_hook2(int keycode, t_mlx *mlx)
{
	ft_putstr("keyhook2\n");
	keycode = 1;
	mlx = NULL;
	return (1);
}

void	ft_julia(void)
{
	t_mlx	*mlx1;
	t_mlx	*mlx2;

	mlx1 = NULL;
	mlx2 = NULL;
	mlx1 = ft_mlx_init(200, 200, mlx1, "fract'ol1");
	mlx2 = ft_mlx_init(200, 200, mlx2, "fract'ol2");
	mlx_key_hook(mlx1->p_win, key_hook1, mlx1);
	mlx_key_hook(mlx2->p_win, key_hook2, mlx2);
	mlx_loop(mlx1->p_mlx);

}

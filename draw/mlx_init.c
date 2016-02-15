/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:58:55 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:29:52 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_mlx	*ft_mlx_init(int width, int height, t_mlx *mlx, char *name)
{
	if (!mlx)
		mlx = (t_mlx *)malloc(sizeof(t_mlx));
	else
		ft_memdel((void **)mlx);
	mlx->width = width;
	mlx->height = height;
	mlx->p_mlx = mlx_init();
	mlx->p_win = mlx_new_window(mlx->p_mlx, mlx->width, mlx->height, name);
	ft_new_image(mlx);
	return (mlx);
}

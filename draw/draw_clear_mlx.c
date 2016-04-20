/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_clear_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:31:57 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/20 10:34:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_clear_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	mlx_destroy_image(mlx->p_mlx, mlx->mlx_img->p_img);
	ft_memdel((void **)&mlx->mlx_img);
	mlx_clear_window(mlx->p_mlx, mlx->p_win);
	mlx_destroy_window(mlx->p_mlx, mlx->p_win);
	ft_memdel((void **)&mlx);
}

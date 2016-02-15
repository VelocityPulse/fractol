/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_reset_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:20:49 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:20:53 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_reset_image(t_mlx *mlx, int color)
{
	int		octet;
	int		position;
	char	*img;

	img = mlx->mlx_img->data;
	octet = mlx->mlx_img->bpp / 8;
	position = 0;
	while (position < mlx->mlx_img->max_size)
	{
		ft_memcpy(img + position, &color, octet);
		position += octet;
	}
}

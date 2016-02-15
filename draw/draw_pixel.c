/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:20:22 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:29:41 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_draw_pixel(t_mlx *mlx, int color, t_pt pt)
{
	long int	position;
	long int	octet;

	octet = mlx->mlx_img->bpp / 8;
	position = (pt.y * mlx->mlx_img->width) + (pt.x * octet);
	if (pt.y >= mlx->height || pt.y < 0 || pt.x >= mlx->width || pt.x < 0)
		return ;
	if (position < 0 || position > mlx->mlx_img->width * mlx->height)
		return ;
	if (ft_memcmp(mlx->mlx_img->data + position, &color, (unsigned)octet) != 0)
		ft_memcpy(mlx->mlx_img->data + position, &color, (unsigned)octet);
}

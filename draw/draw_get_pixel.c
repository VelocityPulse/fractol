/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:27:46 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/06 14:01:12 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int		ft_get_pixel(t_mlx *mlx, t_pt pt)
{
	long int	position;
	long int	octet;

	octet = mlx->mlx_img->bpp / 8;
	position = (pt.y * mlx->mlx_img->width) + (pt.x * octet);
	if (pt.y >= mlx->height || pt.y < 0 || pt.x >= mlx->width || pt.x < 0)
		return (0);
	if (position < 0 || position > mlx->mlx_img->width * mlx->height)
		return (0);
	return (*(unsigned int *)(unsigned long)(mlx->mlx_img->data +
				(mlx->mlx_img->width * pt.y) + (pt.x * octet)));
}

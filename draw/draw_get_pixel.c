/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:27:46 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/21 16:43:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int		ft_get_pixel_image(t_img *img, t_pt pt)
{
	long int	position;
	long int	octet;

	octet = img->bpp / 8;
	position = (pt.y * img->width) + (pt.x * octet);
	if (pt.y >= img->size.y || pt.y < 0 || pt.x >= img->size.x || pt.x < 0)
		return (0);
	if (position < 0 || position > img->width * img->size.y)
		return (0);
	return (*(unsigned int *)(unsigned long)(img->data +
				position));

}

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
				position));
}

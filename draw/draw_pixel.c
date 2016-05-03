/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:10:19 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/03 12:10:21 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_draw_pixel(t_mlx *mlx, int color, t_pt pt)
{
	long int	position;
	void		*data;

	position = (pt.y * mlx->mlx_img->width) + (pt.x * mlx->mlx_img->octet);
	if (pt.y >= mlx->height || pt.y < 0 || pt.x >= mlx->width || pt.x < 0)
		return ;
	if (position < 0 || position > mlx->mlx_img->max_size)
		return ;
	data = mlx->mlx_img->data;
	ft_memcpy(data + position, &color, (unsigned)mlx->mlx_img->octet);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:10:45 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/03 12:10:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_new_image(t_mlx *mlx)
{
	t_img	*img;
	void	*d;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		return ;
	img->endian = 0;
	img->width = mlx->width;
	img->p_img = mlx_new_image(mlx->p_mlx, mlx->width, mlx->height);
	if (!img->p_img)
		return ;
	d = mlx_get_data_addr(img->p_img, &img->bpp, &img->width, &img->endian);
	img->octet = img->bpp / 8;
	img->data = d;
	mlx->mlx_img = img;
	mlx->mlx_img->max_size = img->octet * mlx->width * mlx->height;
}

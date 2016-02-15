/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_isocele.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:17:24 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:17:28 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	ft_draw_isocele(t_area t, t_mlx *mlx, int color)
{
	ft_draw_line(ft_make_line(t.a.x, t.a.y, t.b.x, t.b.y), mlx, color);
	ft_draw_line(ft_make_line(t.b.x, t.b.y, t.c.x, t.c.y), mlx, color);
	ft_draw_line(ft_make_line(t.a.x, t.a.y, t.c.x, t.c.y), mlx, color);
}

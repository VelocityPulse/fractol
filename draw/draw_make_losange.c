/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_losange.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:18:48 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:18:53 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_area	ft_make_losange(t_line line, int mediane)
{
	t_pt	intersection;
	t_area	losange;
	int		ao;
	float	coef;

	intersection.x = (line.start.x + line.end.x) / 2;
	intersection.y = (line.start.y + line.end.y) / 2;
	ao = sqrtf((line.dx / 2) * (line.dx / 2) + (line.dy / 2) * (line.dy / 2));
	if (ao > (float)mediane)
		coef = (float)(ao / (float)mediane);
	else
	{
		coef = (float)((float)mediane / ao);
		coef = 1 / coef;
	}
	losange.a.x = line.start.x;
	losange.a.y = line.start.y;
	losange.c.x = line.end.x;
	losange.c.y = line.end.y;
	losange.d.x = intersection.x - (int)((float)(line.dy / 2) / coef);
	losange.d.y = intersection.y + (int)((float)(line.dx / 2) / coef);
	losange.b.x = intersection.x + (int)((float)(line.dy / 2) / coef);
	losange.b.y = intersection.y - (int)((float)(line.dx / 2) / coef);
	return (losange);
}

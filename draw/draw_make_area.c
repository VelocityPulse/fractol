/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_area.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:18:01 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 12:18:06 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_area	ft_make_area(t_pt a, t_pt b, t_pt c, t_pt d)
{
	t_area area;

	area.a = a;
	area.b = b;
	area.c = c;
	area.d = d;
	return (area);
}

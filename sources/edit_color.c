/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:20:33 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/19 12:56:16 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_edit_color1(t_hook_info *info)
{
	if (info->keycode == 25)
	{
		if (info->f->color_value1 > 1)
			info->f->color_value1--;
		else
			info->f->color_value1 = COLOR_INTERVAL;
	}
	else
	{
		if (info->f->color_value1 < COLOR_INTERVAL)
			info->f->color_value1++;
		else
			info->f->color_value1 = 1;
	}
	ft_calc_color1(info);
}

static void		ft_edit_color2(t_hook_info *info)
{
	static int		variance = 1;
	int				cv2;

	cv2 = info->f->color_value2;
	if ((variance == 1) && (cv2 >= COLOR_INTERVAL || cv2 < 0))
		variance = -1;
	else if ((variance == -1) && (cv2 >= COLOR_INTERVAL || cv2 < 0))
		variance = 1;
	if (info->keycode == 31)
		cv2 += variance;
	else
		cv2 -= variance;
	info->f->color_value2 = cv2;
	ft_calc_color2(info);
}

void			ft_edit_color(t_hook_info *info)
{
	if (info->keycode == 25 || info->keycode == 29)
		ft_edit_color1(info);
	else if (info->keycode == 31 || info->keycode == 35)
		ft_edit_color2(info);
}

/*
** 25 = (
** 29 = )
** 31 = o
** 35 = p
*/

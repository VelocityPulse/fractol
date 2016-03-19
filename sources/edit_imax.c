/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_imax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:22:39 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/19 12:22:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_edit_imax(t_hook_info *info)
{
	if (info->keycode == 30)
		info->f->i_max = llround((double)info->f->i_max * FACTOR_ITER);
	else if (info->keycode == 33 && info->f->i_max > 10)
		info->f->i_max = llround((double)info->f->i_max / FACTOR_ITER);
}

/*
** 30 == hook left -
** 33 == hook right +
*/

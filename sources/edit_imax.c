/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_imax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:37:23 by                   #+#    #+#             */
/*   Updated: 2016/03/10 13:16:45 by                  ###   ########.fr       */
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
 * 30 == hook left -
 * 33 == hook right +
*/

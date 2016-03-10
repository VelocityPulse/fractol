/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:42:28 by                   #+#    #+#             */
/*   Updated: 2016/03/10 13:05:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_edit_pos(t_hook_info *info)
{
	if (info->keycode == 124)
		info->f->pos = ft_add_ptll(info->f->pos, ft_make_ptll(20, 0));
	else if (info->keycode == 123)
		info->f->pos = ft_add_ptll(info->f->pos, ft_make_ptll(-20, 0));
	else if (info->keycode == 126)
		info->f->pos = ft_add_ptll(info->f->pos, ft_make_ptll(0, -20));
	else if (info->keycode == 125)
		info->f->pos = ft_add_ptll(info->f->pos, ft_make_ptll(0, 20));
}

/*
 * 124 right
 * 123 left
 * 126 top
 * 125 bot
*/

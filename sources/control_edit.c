/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_edit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 12:20:12 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/19 12:20:14 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_edit_control(t_hook_info *info)
{
	ft_edit_zoom(info);
	ft_edit_pos(info);
	ft_edit_imax(info);
	ft_edit_color(info);
}

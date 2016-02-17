/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:37:21 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/17 12:20:22 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_exit_all_fractal(t_hook_info *info)
{
	YOLO
	ft_free_list_fractol(info->l_fractol);
	ft_memdel((void **)&info);
	exit(0);
}

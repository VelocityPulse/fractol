/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:37:21 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/07 15:46:18 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_exit_all_fractol(t_hook_info *info)
{
	ft_free_list_mlx(info->l_mlx);
	exit(0);
}

void	ft_exit_one_fractol(t_hook_info *info)
{
	ft_free_one_mlx_list(info->l_mlx, info->n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:37:21 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/17 15:58:00 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_exit_all_fractol(t_hook_info *info)
{
	ft_free_fractol_list(info->l_fractol);
	ft_memdel((void **)&info);
	exit(0);
}

void	ft_exit_one_fractol(t_hook_info *info)
{
	ft_free_one_fractol_list(info->l_fractol, info->n);
	ft_memdel((void **)&info);
}

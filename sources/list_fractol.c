/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:01:47 by                   #+#    #+#             */
/*   Updated: 2016/02/16 14:07:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_fractol	*ft_add_list_fractol(void)
{
	t_fractol	*list;

	list = (t_fractol *)ft_memalloc(sizeof(t_fractol));
	list->n = 0;
	list->mlx = NULL;
	list->next = NULL;
	return (list);
}

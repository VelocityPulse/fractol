/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:01:47 by                   #+#    #+#             */
/*   Updated: 2016/02/17 12:12:38 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_fractol	*ft_add_list_fractol(t_fractol *begin, t_mlx *mlx, int n)
{
	t_fractol	*list;

	if (!begin)
	{
		begin = ft_new_list_fractol();
		begin->mlx = mlx;
		begin->n = n;
		return (begin);
	}
	list = begin;
	while (list->next)
		list = list->next;
	list->next = ft_new_list_fractol();
	list->mlx = mlx;
	list->n = n;
	return (begin);
}

t_fractol	*ft_new_list_fractol(void)
{
	t_fractol	*list;

	list = (t_fractol *)ft_memalloc(sizeof(t_fractol));
	list->n = 0;
	list->mlx = NULL;
	list->next = NULL;
	return (list);
}

void		*ft_free_list_fractol(t_fractol *begin)
{
	t_fractol	*temp;

	if (!begin)
	{
		TEST
		return (NULL);
	}
	while (begin)
	{
		temp = begin->next;
		ft_clear_mlx(begin->mlx);
		ft_memdel((void **)&begin);
		begin = temp;
	}
	return (begin);
}

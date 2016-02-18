/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:58:17 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/18 14:58:19 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_fractol		*ft_add_list_fractol(t_fractol *begin, t_mlx *mlx, int n)
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
	list = list->next;
	list->mlx = mlx;
	list->n = n;
	return (begin);
}

t_fractol		*ft_new_list_fractol(void)
{
	t_fractol	*list;

	list = (t_fractol *)ft_memalloc(sizeof(t_fractol));
	list->n = 0;
	list->mlx = NULL;
	list->next = NULL;
	return (list);
}

t_fractol		*ft_free_fractol_list(t_fractol *begin)
{
	t_fractol	*temp;

	if (!begin)
		return (NULL);
	while (begin)
	{
		temp = begin->next;
		ft_clear_mlx(begin->mlx);
		ft_memdel((void **)&begin);
		begin = temp;
	}
	return (begin);
}

t_fractol		*ft_free_one_fractol_list(t_fractol *begin, int n)
{
	t_fractol	*parent;
	t_fractol	*list;

	list = begin;
	if (list->next && (parent = list))
		list = list->next;
	while (list)
	{
		if (list->next && list->n == n)
		{
			parent->next = list->next;
			ft_clear_mlx(list->mlx);
			ft_memdel((void **)&list);
			return (begin);
		}
		else if (!list->next && list->n == n)
		{
			ft_clear_mlx(list->mlx);
			ft_memdel((void **)&parent->next);
			return (begin);
		}
		parent = list;
		list = list->next;
	}
	return (begin);
}

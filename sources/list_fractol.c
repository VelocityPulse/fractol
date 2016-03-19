/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:58:17 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/19 12:46:33 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_list_mlx		*ft_add_list_mlx(t_list_mlx *begin, t_hook_info *info, int n)
{
	t_list_mlx		*list;

	if (!begin)
	{
		begin = ft_new_list_mlx();
		begin->info = info;
		begin->n = n;
		return (begin);
	}
	list = begin;
	while (list->next)
		list = list->next;
	list->next = ft_new_list_mlx();
	list = list->next;
	list->info = info;
	list->n = n;
	return (begin);
}

t_list_mlx		*ft_new_list_mlx(void)
{
	t_list_mlx		*list;

	list = (t_list_mlx *)ft_memalloc(sizeof(t_list_mlx));
	list->n = 0;
	list->info = NULL;
	list->next = NULL;
	return (list);
}

t_list_mlx		*ft_free_list_mlx(t_list_mlx *begin)
{
	t_list_mlx		*temp;
	t_hook_info		*info;

	if (!begin)
		return (NULL);
	while (begin)
	{
		temp = begin->next;
		info = (t_hook_info *)begin->info;
		ft_clear_mlx(info->current_mlx);
		ft_memdel((void **)&info->f);
		ft_memdel((void **)&info);
		ft_memdel((void **)&begin);
		begin = temp;
	}
	return (begin);
}

static void		*ft_list_del(t_list_mlx *list, t_list_mlx *b)
{
	t_hook_info		*info;

	info = (t_hook_info *)list->info;
	ft_clear_mlx(info->current_mlx);
	ft_memdel((void **)&info->f);
	ft_memdel((void *)&info);
	ft_memdel((void **)&list);
	return (b);
}

t_list_mlx		*ft_free_one_mlx_list(t_list_mlx *begin, int n)
{
	t_list_mlx		*parent;
	t_list_mlx		*list;

	list = begin;
	if (list->next && (parent = list))
		list = list->next;
	while (list)
	{
		if (list->next && list->n == n)
		{
			parent->next = list->next;
			return (ft_list_del(list, begin));
		}
		else if (!list->next && list->n == n)
		{
			ft_memdel((void **)&parent->next);
			return (ft_list_del(list, begin));
		}
		parent = list;
		list = list->next;
	}
	return (begin);
}

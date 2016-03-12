/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:41:01 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/12 12:19:54 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_display_list(char *str)
{
	if (str)
	{
		ft_putchar('"');
		ft_putstr(str);
		ft_putchar('"');
		ft_putstr(" is not a fracal.\n");
	}
	ft_putstr("List of available fractals :\n");
	ft_putstr(" Julia\n");
	ft_putstr(" Mandelbrot\n");
	ft_putstr(" Buddhabrot\n");
	exit(0);
}

void	ft_start(int ac, char **av)
{
	t_list_mlx	*begin;
	int			i;

	i = 1;
	begin = NULL;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (!ft_strcmp(av[i], "Julia"))
				begin = ft_add_julia(i, begin);
			else if (!ft_strcmp(av[i], "Mandelbrot"))
				begin = ft_add_mandelbrot(i, begin);
			else if (!ft_strcmp(av[i], "Buddhabrot"))
				begin = ft_add_buddhabrot(i, begin);
			else
				ft_display_list(av[i]);
			i++;
		}
		mlx_loop(((t_hook_info *)begin->info)->current_mlx);
	}
	else
		ft_display_list(NULL);
}

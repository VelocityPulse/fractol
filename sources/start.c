/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:41:01 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/16 15:48:52 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_display_list(char *str)
{
	if (str)
	{
		ft_putstr(str);
		ft_putstr(" is not a fracals.\n");
	}
	ft_putstr("List of available fractals :\n");
	ft_putstr("-Julia\n");
	ft_putstr("-Mandelbrot\n");
}

void	ft_start(int ac, char **av)
{
	t_fractol	*begin;
	int			i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (!ft_strcmp(av[i], "Julia"))
				begin = ft_add_list_fractol(begin, ft_julia(i), i);
			else if (!ft_strcmp(av[i], "Mandelbrot"))
				begin = ft_add_list_fractol(begin, ft_mandelbrot(i), i);
			else
				ft_display_list(av[i]);
			i++;
		}
		mlx_loop(begin->mlx->p_mlx);
	}
	else
		ft_display_list(NULL);
}

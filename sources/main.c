/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 15:24:00 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/16 15:08:56 by cchameyr         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (!ft_strcmp(argv[i], "Julia"))
				mlx = ft_julia(i);
			else if (!ft_strcmp(argv[i], "Mandelbrot"))
				mlx = ft_mandelbrot(i);
			else
				ft_display_list(argv[i]);
			i++;
		}
		mlx_loop(mlx->p_mlx);
	}
	else
		ft_display_list(NULL);
	return (0);
}

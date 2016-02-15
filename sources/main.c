/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 15:24:00 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 17:13:54 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "Julia"))
			ft_julia();
//		else if (!ft_strcmp(argv[1], "Mandelbrot"))
//			ft_mandelbrot();
	}
	return (0);
}

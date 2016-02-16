/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 15:24:10 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/16 15:45:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "draw.h"
# include "mlx.h"
# include "X.h"

typedef struct	s_fractol
{
	int					n;
	t_mlx				*mlx;
	struct s_fractol	*next;
}				t_fractol;

void			ft_start(int ac, char **av);

t_mlx			*ft_julia(int n);
t_mlx			*ft_mandelbrot(int n);

t_fractol		*ft_new_list_fractol(void);
t_fractol		*ft_add_list_fractol(t_fractol *begin, t_mlx *mlx, int n);
void			*ft_free_list_fractol(t_fractol *begin);

#endif

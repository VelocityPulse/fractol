/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 15:24:10 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/05 21:12:42 by                  ###   ########.fr       */
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

# include "debug.h"

# define W_WIDTH 1080
# define W_HEIGHT 750
# define FACTOR_ZOOM 1.5

typedef struct	s_fractol
{
	int					n;
	t_mlx				*mlx;
	struct s_fractol	*next;
}				t_fractol;

typedef struct	s_mouse_info
{
	int			button;
	long int	px;
	long int	py;
	int			nb_zoom;
}				t_mouse_info;

typedef struct	s_hook_info
{
	int				n;
	int				keycode;
	t_mlx			*current_mlx;
	t_fractol		*l_fractol;
	t_mouse_info	mouse;
}				t_hook_info;

void			ft_start(int ac, char **av);
void			ft_exit_all_fractol(t_hook_info *info);
void			ft_exit_one_fractol(t_hook_info *info);

t_fractol		*ft_add_julia(int n, t_fractol *begin);
void			ft_julia(t_hook_info *info);
t_fractol		*ft_add_mandelbrot(int n, t_fractol *begin);
void			ft_mandelbrot(t_hook_info *info);

t_fractol		*ft_new_list_fractol(void);
t_fractol		*ft_add_list_fractol(t_fractol *begin, t_mlx *mlx, int n);
t_fractol		*ft_free_fractol_list(t_fractol *begin);
t_fractol		*ft_free_one_fractol_list(t_fractol *begin, int n);

#endif

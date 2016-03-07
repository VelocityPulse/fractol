/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 15:24:10 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/07 16:29:26 by cchameyr         ###   ########.fr       */
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

typedef struct	s_list_mlx
{
	int					n;
	void				*info;
	struct s_list_mlx	*next;
}				t_list_mlx;

typedef struct	s_fractal
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	double		i;
	double		i_max;
	t_pt		max;
	t_pt		min;
	t_pt		index;
	int			image_x;
	int			image_y;
}				t_fractal;

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
	t_list_mlx		*l_mlx;
	t_mouse_info	mouse;
	t_fractal		*f;
}				t_hook_info;

void			ft_start(int ac, char **av);
void			ft_exit_all_fractol(t_hook_info *info);
void			ft_exit_one_fractol(t_hook_info *info);

t_list_mlx		*ft_add_julia(int n, t_list_mlx *begin);
void			ft_julia(t_hook_info *info);
t_list_mlx		*ft_add_mandelbrot(int n, t_list_mlx *begin);
void			ft_mandelbrot(t_hook_info *info);

t_list_mlx		*ft_new_list_mlx(void);
t_list_mlx		*ft_add_list_mlx(t_list_mlx *begin, t_hook_info *info, int n);
t_list_mlx		*ft_free_list_mlx(t_list_mlx *begin);
t_list_mlx		*ft_free_one_mlx_list(t_list_mlx *begin, int n);

#endif

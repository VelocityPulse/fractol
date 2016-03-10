/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 15:24:10 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/10 12:09:43 by                  ###   ########.fr       */
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
	int			i;
	int			i_max;
	t_ptll		min;
	t_ptll 		max;
	int			nb_zoom;
	t_ptll		pos;
}				t_fractal;

typedef struct	s_mouse_info
{
	int			button;
	t_ptll		pos;
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

int				mouse_hook_mandelbrot(int btn, int x, int y, t_hook_info *info);
int				key_hook_mandelbrot(int keycode, t_hook_info *info);

void			ft_start(int ac, char **av);
void			ft_exit_all_fractol(t_hook_info *info);
void			ft_exit_one_fractol(t_hook_info *info);

void			ft_edit_zoom(t_hook_info *info);
void			ft_edit_imax(t_hook_info *info);
void			ft_edit_reset(t_hook_info *info);

t_list_mlx		*ft_add_julia(int n, t_list_mlx *begin);
void			ft_julia(t_hook_info *info);

t_list_mlx		*ft_add_mandelbrot(int n, t_list_mlx *begin);
void			ft_mandelbrot(t_hook_info *info);
void			ft_mandelbrot_iter(t_fractal *f, t_ptll pos, t_pt px, t_pt i);
void			ft_mandelbrot_frame_init(t_fractal *f);

t_list_mlx		*ft_new_list_mlx(void);
t_list_mlx		*ft_add_list_mlx(t_list_mlx *begin, t_hook_info *info, int n);
t_list_mlx		*ft_free_list_mlx(t_list_mlx *begin);
t_list_mlx		*ft_free_one_mlx_list(t_list_mlx *begin, int n);

#endif

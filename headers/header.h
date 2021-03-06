/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 15:24:10 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/19 16:40:13 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "draw.h"
# include "../libmlx/mlx.h"
# include "../libmlx/X.h"

# define W_WIDTH 1080
# define W_HEIGHT 750
# define FACTOR_ZOOM 1.5
# define FACTOR_ITER 1.12
# define COLOR_INTERVAL 40

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
	t_ptll		max;
	int			nb_zoom;
	t_ptll		pos;
	int			color_value1;
	int			color_value2;
	t_rgb		rgb_max1;
	t_rgb		rgb_max2;
	t_ptll		mouse_pos;
}				t_fractal;

typedef struct	s_mouse_info
{
	int			button;
	int			block;
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

void			ft_start_burningship_hook(t_hook_info *info);
int				mouse_hook_burningship(int b, int x, int y, t_hook_info *info);
int				key_hook_burningship(int keycode, t_hook_info *info);

void			ft_start_mandelbrot_hook(t_hook_info *info);
int				mouse_hook_mandelbrot(int btn, int x, int y, t_hook_info *info);
int				key_hook_mandelbrot(int keycode, t_hook_info *info);

void			ft_start_julia_hook(t_hook_info *info);
int				key_hook_julia(int keycode, t_hook_info *info);
int				mouse_hook_julia(int x, int y, t_hook_info *info);
int				click_hook_julia(int btn, int x, int y, t_hook_info *info);

void			ft_start_juliabs_hook(t_hook_info *info);
int				key_hook_juliabs(int keycode, t_hook_info *info);
int				mouse_hook_juliabs(int x, int y, t_hook_info *info);
int				click_hook_juliabs(int btn, int x, int y, t_hook_info *info);

void			ft_start(int ac, char **av);
void			ft_exit_all_fractol(t_hook_info *info);
void			ft_exit_one_fractol(t_hook_info *info);

void			ft_edit_control(t_hook_info *info);
void			ft_edit_zoom(t_hook_info *info);
void			ft_calc_pos(t_hook_info *info, t_ptll mouse_pos);
void			ft_edit_imax(t_hook_info *info);
void			ft_edit_reset_mandelbrot(t_hook_info *info);
void			ft_edit_reset_julia(t_hook_info *info);
void			ft_edit_reset_burningship(t_hook_info *info);
void			ft_edit_reset_juliabs(t_hook_info *info);
void			ft_edit_pos(t_hook_info *info);
void			ft_edit_color(t_hook_info *info);

void			ft_calc_color(t_hook_info *info);
void			ft_calc_color1(t_hook_info *info);
void			ft_calc_color2(t_hook_info *info);
void			ft_trace_color(t_hook_info *info, t_pt px);

t_list_mlx		*ft_add_juliabs(int n, t_list_mlx *begin);
void			ft_juliabs(t_hook_info *info);
void			ft_juliabs_iter(t_fractal *f, t_ptll pos, t_pt px, t_pt i);

t_list_mlx		*ft_add_burningship(int n, t_list_mlx *begin);
void			ft_burningship(t_hook_info *info);
void			ft_burningship_iter(t_fractal *f, t_ptll pos, t_pt px, t_pt i);

t_list_mlx		*ft_add_julia(int n, t_list_mlx *begin);
void			ft_julia(t_hook_info *info);
void			ft_julia_iter(t_fractal *f, t_ptll pos, t_pt px, t_pt i);

t_list_mlx		*ft_add_mandelbrot(int n, t_list_mlx *begin);
void			ft_mandelbrot(t_hook_info *info);
void			ft_mandelbrot_iter(t_fractal *f, t_ptll pos, t_pt px, t_pt i);
void			ft_mandelbrot_frame_init(t_fractal *f);

t_list_mlx		*ft_new_list_mlx(void);
t_list_mlx		*ft_add_list_mlx(t_list_mlx *begin, t_hook_info *info, int n);
t_list_mlx		*ft_free_list_mlx(t_list_mlx *begin);
t_list_mlx		*ft_free_one_mlx_list(t_list_mlx *begin, int n);

#endif

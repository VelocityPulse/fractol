/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:17:56 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/02 15:12:55 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_H
# define _DRAW_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "draw_structs.h"
# include "../headers/libft.h"
# include "../libmlx/mlx.h"

t_mlx		*ft_mlx_init(int width, int height, char *name);
void		ft_clear_mlx(t_mlx *mlx);
void		ft_new_image(t_mlx *mlx);
void		ft_flush_image(t_mlx *x);
void		ft_draw_pixel(t_mlx *mlx, int color, t_pt pt);
int			ft_get_pixel(t_mlx *mlx, t_pt pt);
int			ft_get_pixel_image(t_img *img, t_pt pt);
void		ft_reset_image(t_mlx *mlx, int color);

t_line		ft_make_line(int x1, int y1, int x2, int y2);
t_area		ft_make_area(t_pt a, t_pt b, t_pt c, t_pt d);
t_area		ft_make_losange(t_line line, int mediane);
t_area		ft_make_isocele(t_line line, int mediane);
t_vector	ft_make_vector(float x, float y, float z);

t_matrix	ft_init_matrix(t_pt pos);
t_matrix	ft_multiply_matrix(t_matrix m1, t_matrix m2);
t_vector	ft_add_vector(t_vector v, float x, float y, float z);
t_vector	ft_multiply_vector(t_vector v, float x, float y, float z);

t_matrix	ft_rotate_matrix_x(float rot);
t_matrix	ft_rotate_matrix_y(float rot);
t_matrix	ft_rotate_matrix_z(float rot);
t_pt3d		**ft_add_scale(t_pt3d **tab, t_pt size, t_pt3d scale);
t_pt		**ft_add_pos(t_pt **tab, t_pt size, t_pt pos);

t_pt		ft_apply_matrix(t_pt3d pt, t_matrix m);
void		ft_array_layout(t_pt3d *pts, int size, t_pt *new_pt, t_matrix t);

t_rgb		ft_get_rgb(int hexa);
int			ft_get_hexa(t_rgb rgb);
int			ft_get_hexa_rgb(int r, int g, int b);
t_rgb		ft_find_color_gradient(t_dual_color c, int n, int p);
int			ft_divide_color(int color);

void		ft_draw_line(t_line l, t_mlx *mlx, int color);
void		ft_draw_horizontal(t_line l, t_mlx *mlx, int variance, int color);
void		ft_draw_vertical(t_line l, t_mlx *mlx, int variance, int color);
void		ft_draw_bresenham(t_line l, t_mlx *mlx, t_pt variance, int color);
void		ft_draw_perimeter(t_pt *list, int size, t_mlx *mlx, int color);

void		ft_draw_color_line(t_line l, t_mlx *mlx, int c1, int c2);
void		ft_draw_horizontal_c(t_line l, t_mlx *mlx, int var, t_dual_color c);
void		ft_draw_vertical_c(t_line l, t_mlx *mlx, int var, t_dual_color c);
void		ft_draw_bresenham_c(t_line l, t_mlx *mlx, t_pt var, t_dual_color c);

void		ft_draw_rect(t_line line, t_mlx *mlx, int color);
void		ft_draw_losange(t_area l, t_mlx *mlx, int color);
void		ft_draw_isocele(t_area t, t_mlx *mlx, int color);

#endif

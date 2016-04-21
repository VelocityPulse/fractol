/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:17:17 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/21 14:42:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_STRUCTS_H
# define _DRAW_STRUCTS_H

# include "../headers/libft.h"

typedef struct	s_area
{
	t_pt		a;
	t_pt		b;
	t_pt		c;
	t_pt		d;
}				t_area;

typedef struct	s_line
{
	t_pt		start;
	t_pt		end;
	int			dx;
	int			dy;
}				t_line;

typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct	s_dual_color
{
	t_rgb	c1;
	t_rgb	c2;
}				t_dual_color;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_matrix
{
	t_vector	x;
	t_vector	y;
	t_vector	z;
	t_pt		pos;
}				t_matrix;

typedef struct	s_matrix_rot
{
	t_matrix	mx;
	t_matrix	my;
	t_matrix	mz;
	t_matrix	m;
}				t_matrix_rot;

typedef struct	s_img
{
	int			loaded;
	char		*data;
	void		*p_img;
	t_pt		size;
	int			width;
	int			bpp;
	int			endian;
	int			max_size;
}				t_img;

typedef struct	s_mlx
{
	void		*p_mlx;
	void		*p_win;
	int			height;
	int			width;
	t_img		*mlx_img;
}				t_mlx;

#endif

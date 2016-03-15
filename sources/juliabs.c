/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:17:39 by                   #+#    #+#             */
/*   Updated: 2016/03/15 17:43:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static t_fractal		*ft_init_juliabs_fractal(void)
{
	t_fractal *f;

	f = (t_fractal *)ft_memalloc(sizeof(t_fractal));
	f->x1 = 0;
	f->x2 = 0;
	f->y1 = 0;
	f->y2 = 0;
	f->min = ft_make_ptll(0, 0);
	f->max = ft_make_ptll(0, 0);
	f->zoom = 300;
	f->i_max = 70;
	f->i = 0;
	f->pos = ft_make_ptll(0, 0);
	f->nb_zoom = 0;
	f->color_value1 = 6;
	f->color_value2 = 0;
	return (f);
}

void			ft_juliabs(t_hook_info *info)
{
	t_fractal	*f;
	t_pt		p;
	t_ptll		index;

	f = info->f;
	ft_reset_image(info->current_mlx, 0);
	ft_edit_reset_julia(info);
	ft_edit_control(info);
	ft_mandelbrot_frame_init(f);
	p.x = 0;
	index.x = f->min.x - 1;
	while ((++index.x < f->max.x) && !(p.y = 0))
	{
		index.y = f->min.y - 1;
		while (++index.y < f->max.y)
		{
			f->mouse_pos = info->mouse.pos;
			ft_juliabs_iter(f, info->f->pos, p, ft_make_pt(-1, f->i_max));
			ft_trace_color(info, p);
			p.y++;
		}
		p.x++;
	}
	ft_flush_image(info->current_mlx);
}

t_list_mlx			*ft_add_juliabs(int n, t_list_mlx *begin)
{
	t_hook_info		*info;
	static int		i = 1;
	char			*str1;
	char			*str2;

	info = (t_hook_info *)ft_memalloc(sizeof(t_hook_info));
	info->n = n;
	info->f = ft_init_juliabs_fractal();
	ft_calc_color(info);
	str2 = ft_itoa(i);
	if (n == 1)
		str1 = ft_strjoin("main : fract'ol Julia Burningship ", str2);
	else
		str1 = ft_strjoin("fract'ol Julia Burningship ", str2);
	info->current_mlx = ft_mlx_init(W_WIDTH, W_HEIGHT, str1);
	begin = ft_add_list_mlx(begin, info, n);
	info->l_mlx = begin;
	ft_start_juliabs_hook(info);
	if (n > 1)
		ft_juliabs(info);
	i++;
	ft_memdel((void **)&str1);
	ft_memdel((void **)&str2);
	ft_juliabs(info);
	return (begin);
}

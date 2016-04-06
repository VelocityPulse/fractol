#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/01/23 00:01:04 by                   #+#    #+#             *#
#*   Updated: 2016/02/11 12:25:46 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			draw.a

SRCS =			./draw_pixel.c \
				./draw_reset_image.c \
				./new_image.c \
				./mlx_init.c \
				./draw_make_line.c \
				./draw_line.c \
				./draw_make_area.c \
				./draw_rect.c \
				./draw_make_losange.c \
				./draw_losange.c \
				./draw_make_isocele.c \
				./draw_isocele.c \
				./draw_make_matrix.c \
				./draw_init_matrix.c \
				./draw_make_vector.c \
				./draw_add_vector.c \
				./draw_multiply_matrix.c \
				./draw_apply_matrix.c \
				./draw_array_layout.c \
				./draw_perimeter.c \
				./draw_flush_image.c \
				./draw_multiply_vector.c \
				./draw_add_scale.c \
				./draw_add_pos.c \
				./draw_clear_mlx.c \
				./draw_color_line.c \
				./draw_get_rgb.c \
				./draw_get_hexa.c \
				./draw_find_color_gradient.c \
				./draw_get_pixel.c

OBJS =			./draw_pixel.o \
				./new_image.o \
				./draw_reset_image.o \
				./mlx_init.o \
				./draw_make_line.o \
				./draw_line.o \
				./draw_make_area.o \
				./draw_rect.o \
				./draw_make_losange.o \
				./draw_losange.o \
				./draw_make_isocele.o \
				./draw_isocele.o \
				./draw_make_matrix.o \
				./draw_init_matrix.o \
				./draw_make_vector.o \
				./draw_add_vector.o \
				./draw_multiply_matrix.o \
				./draw_apply_matrix.o \
				./draw_array_layout.o \
				./draw_perimeter.o \
				./draw_flush_image.o \
				./draw_multiply_vector.o \
				./draw_add_scale.o \
				./draw_add_pos.o \
				./draw_clear_mlx.o \
				./draw_color_line.o \
				./draw_get_rgb.o \
				./draw_get_hexa.o \
				./draw_find_color_gradient.o \
				./draw_get_pixel.o

FLAGS = 		-Wall -Wextra -Werror

CC =			gcc

RM =			rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS):
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX)

re: fclean all

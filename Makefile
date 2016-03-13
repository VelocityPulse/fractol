# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 16:45:32 by cchameyr          #+#    #+#              #
#*   Updated: 2016/03/10 22:32:05 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME =			fractol

SRC =			./sources/main.c \
				./sources/julia.c \
				./sources/mandelbrot.c \
				./sources/list_fractol.c \
				./sources/start.c \
				./sources/exit.c \
				./sources/mandelbrot_core.c \
				./sources/mandelbrot_hook.c \
				./sources/control_edit.c \
				./sources/edit_zoom.c \
				./sources/edit_imax.c \
				./sources/edit_reset.c \
				./sources/edit_pos.c \
				./sources/edit_color.c \
				./sources/calc_color.c \
				./sources/trace_color.c \
				./sources/julia_hook.c \
				./sources/julia_core.c \
				./sources/buddhabrot.c \
				./sources/buddhabrot_hook.c

OBJS =			main.o \
				julia.o \
				mandelbrot.o \
				list_fractol.o \
				start.o \
				exit.o \
				mandelbrot_core.o \
				mandelbrot_hook.o \
				control_edit.o \
				edit_zoom.o \
				edit_imax.o \
				edit_reset.o \
				edit_pos.o \
				edit_color.o \
				calc_color.o \
				trace_color.o \
				julia_hook.o \
				julia_core.o \
				buddhabrot.o \
				buddhabrot_hook.o

DRAW =			./draw/draw.a

LIBFT =			./libft/libft.a

LIBMLX =		./libmlx/libmlx.a

LMLX =			#-lmlx

FRAMEWORK =		$(LMLX) -framework OpenGL -framework AppKit

FLAGS =			-Wall -Wextra -Werror -fsanitize=address

CC =			gcc

RM =			rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(DRAW) $(OBJS)
	$(CC) $(FLAGS) $(FRAMEWORK) $(OBJS) $(LIBFT) $(LIBMLX) $(DRAW) -o $(NAME)

$(OBJS): $(LIBFT) $(LIBMLX) $(DRAW)
	$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
	make -C ./libft/

$(DRAW):
	make -C ./draw/

$(LIBMLX):
	make -C ./libmlx/

clean:
	$(RM) $(OBJS)
	make clean -C ./draw/
	make clean -C ./libft/
	make clean -C ./libmlx/

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(DRAW) $(LIBMLX)

re: fclean all

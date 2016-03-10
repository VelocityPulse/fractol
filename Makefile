# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 16:45:32 by cchameyr          #+#    #+#              #
#*   Updated: 2016/03/10 12:10:13 by                  ###   ########.fr       *#
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
				./sources/edit_zoom.c \
				./sources/edit_imax.c \
				./sources/edit_reset.c

OBJS =			main.o \
				julia.o \
				mandelbrot.o \
				list_fractol.o \
				start.o \
				exit.o \
				mandelbrot_core.o \
				mandelbrot_hook.o \
				edit_zoom.o \
				edit_imax.o \
				edit_reset.o

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

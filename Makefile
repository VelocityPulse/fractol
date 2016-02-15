# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 16:45:32 by cchameyr          #+#    #+#              #
#    Updated: 2016/02/15 17:01:26 by cchameyr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fractol

SRC =			./sources/main.c

OBJS =			main.o

DRAW =			./draw/draw.a

LIBFT =			./libft/libft.a

LIBMLX =		./libmlx/libmlx.a

LMLX =			-lmlx

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

clean:
	$(RM) $(OBJS)
	make fclean -C ./draw/
	make fclean -C ./libft/

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(DRAW)

re: fclean all

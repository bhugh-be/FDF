# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhugh-be <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 18:21:10 by bhugh-be          #+#    #+#              #
#    Updated: 2019/04/05 18:21:12 by bhugh-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

GCCFLAGS =  -Wall -Wextra -Werror

INCLUDES = -I ./includes

LIB_PATH = ./libft

LIB = ./libft/libft.a

SRC  = ./srcs/fdf.c\

INCLUDES = -I ./includes

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
			@make -C $(LIB_PATH)
			@gcc $(GCCFLAGS) $(SRC) $(LIB) -o $(NAME) $(INCLUDES) -lmlx -framework OpenGL -framework Appkit

clean:
			@make clean -C $(LIB_PATH)
			@rm -f $(OBJ)

fclean: clean
			@make fclean -C $(LIB_PATH)
			@rm -f $(NAME)

re: fclean all

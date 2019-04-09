# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 18:21:10 by bhugh-be          #+#    #+#              #
#    Updated: 2019/04/08 23:36:05 by bhugh-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS =  -Wall -Wextra -Werror

LIB_MLX =  -lmlx -framework OpenGL -framework Appkit

LIB_PATH = ./libft

LIB = ./libft/libft.a

SRC  = fdf.c\
		wu_algorithm.c\
		validation.c\
		drawmatrix.c\
		hooks.c

INCLUDES = -I ./includes -I ./libft/includes

OBJ_DIR = ./objs

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

SRC_DIR = ./srcs

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJ)
			@make -C $(LIB_PATH)
			@gcc  -g $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) $(INCLUDES) $(LIB_MLX)

clean:
			@make clean -C $(LIB_PATH)
			@rm -f $(OBJ)

fclean: clean
			@make fclean -C $(LIB_PATH)
			@rm -f $(NAME)

re: fclean all

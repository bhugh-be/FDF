# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 17:45:44 by bhugh-be          #+#    #+#              #
#    Updated: 2019/04/07 04:46:39 by bhugh-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GCCFLAGS = -Wall -Wextra -Werror

SRC_DIR = $(addprefix ./srcs/,$(SRC))

OBJ_DIR = objs

SRC  = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_tolower.c \
		ft_toupper.c \
		\
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		\
		ft_list_new.c\
		ft_list_add.c\
		ft_list_count.c\
		ft_list_free.c\
		\
		ft_isspace.c\
		ft_wordcount.c\
		ft_strnlen.c\
		ft_swap.c\
		ft_strndup.c\
		ft_bsort.c\
		ft_sqrt.c\
		ft_max_elem.c\
		get_next_line.c\
		ft_swap_double.c\
		ft_atoi_base.c\
		ft_vector_len.c\
		ft_die.c\

OBJ_DIR = ./objs

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME):
		@gcc $(GCCFLAGS) -c $(SRC_DIR) -I ./includes
		@mkdir -p $(OBJ_DIR) && mv $(SRC:.c=.o) ./$(OBJ_DIR)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

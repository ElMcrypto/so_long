# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 17:20:51 by eelmoham          #+#    #+#              #
#    Updated: 2022/03/09 02:05:50 by eelmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS  = ./mandatory/so_long.c \
		./mandatory/ft_split.c \
		./mandatory/func.c \
		./mandatory/map_errors.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

header =./mandatory/so_long.h

OBJ = $(SRCS:.c=.o)

FLAGS = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ) $(header)
	cc $(OBJ) $(FLAGS) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f so_long

re : fclean $(NAME)

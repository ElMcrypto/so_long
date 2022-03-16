# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 17:20:51 by eelmoham          #+#    #+#              #
#    Updated: 2022/03/16 21:04:25 by eelmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long_bonus

SRCS  = ./so_long_bonus.c \
		./ft_split_bonus.c \
		./ft_itoa.c \
		./patrole.c \
		./func_bonus.c \
		./func_bonus_2.c \
		./map_errors_bonus.c \
		../get_next_line/get_next_line.c \
		../get_next_line/get_next_line_utils.c

header =./so_long_bonus.h

OBJ = $(SRCS:.c=.o)
OBJS_BONUS = $(bonus:.c=.o)

FLAGS =gcc -Wall -Wextra -Werror 

LMLX = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ) $(header)
	$(FLAGS)  $(OBJ) $(LMLX) -o $(NAME)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f so_long_bonus

re : fclean $(NAME)

.PHONY: clean fclean re
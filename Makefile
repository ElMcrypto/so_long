# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 17:20:51 by eelmoham          #+#    #+#              #
#    Updated: 2022/03/20 00:17:45 by eelmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = so_long_bonus

SRCS  = ./mandatory/so_long.c \
		./mandatory/ft_split.c \
		./mandatory/func.c \
		./mandatory/free_all.c \
		./mandatory/ft_putnbr.c \
		./mandatory/map_errors.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

bonus = ./bonus/so_long_bonus.c \
		./bonus/ft_split_bonus.c \
		./bonus/ft_itoa.c \
		./bonus/free_all_bonus.c \
		./bonus/patrole.c \
		./bonus/func_bonus.c \
		./bonus/func_bonus_2.c \
		./bonus/map_errors_bonus.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

header	 =./mandatory/so_long.h
header_b =./bonus/so_long_bonus.h

OBJ = $(SRCS:%.c=%.o)
OBJ_bonus = $(bonus:.c=.o)

%.o : %.c $(header)
	 $(FLAGS) -c $< -o $@
FLAGS =gcc -Wall -Wextra -Werror 

LMLX = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ) $(header)
	$(FLAGS) $(OBJ) $(LMLX) -o $(NAME)

bonus: $(OBJ_bonus) $(header_b)
	$(FLAGS) $(OBJ_bonus) $(LMLX) -o so_long_bonus

clean :
	rm -f $(OBJ)
	rm -f $(OBJ_bonus)
fclean : clean
	rm -f so_long
	rm -f so_long_bonus

re : fclean $(NAME)

.PHONY: clean fclean re bonus
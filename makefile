# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 01:00:28 by mohammoh          #+#    #+#              #
#    Updated: 2023/08/22 22:16:08 by mohammoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ./src/main.c \
		./stack_utils_op/stack_utils.c ./stack_utils_op/stack_utils2.c ./stack_utils_op/stack_utils3.c\
		./stack_utils_op/stack_op_swap.c ./stack_utils_op/stack_op_push.c ./stack_utils_op/stack_op_shift_up.c ./stack_utils_op/stack_op_shift_down.c\
		./sort_utils/sort_utils.c ./sort_utils/sort_utils2.c ./src/check_sort.c ./src/ft_sort_big.c\
		./src/ft_ps_atoi.c ./src/ft_split.c \

OBJECTS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
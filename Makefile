# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 18:28:19 by yaabdoul          #+#    #+#              #
#    Updated: 2025/12/28 16:26:13 by yaabdoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -fsanitize=address -g3 -Wall -Wextra -Werror

SRC_DIRS    = ./src/operations ./src/sort ./src/stack ./src/utils

SRCS        = push_swap.c \
              src/operations/operations_push.c \
              src/operations/operations_rotate.c \
              src/operations/operations_reverse_rotate.c \
              src/operations/operations_swap.c \
              src/sort/sort_big.c \
              src/sort/sort_big_utils.c \
              src/sort/sort_big_utils1.c \
              src/sort/sort_small.c \
              src/sort/sort_utils.c \
              src/sort/sort_utils1.c \
              src/stack/stack_init.c \
              src/utils/ft_split.c \
              src/utils/parsing.c \
              src/utils/parsing_utils.c

BONUS_SRCS  = src/bonus/checker.c \
              src/bonus/read_operations.c \
              src/operations/operations_push.c \
              src/operations/operations_rotate.c \
              src/operations/operations_reverse_rotate.c \
              src/operations/operations_swap.c \
              src/sort/sort_big.c \
              src/sort/sort_big_utils.c \
              src/sort/sort_big_utils1.c \
              src/sort/sort_small.c \
              src/sort/sort_utils.c \
              src/sort/sort_utils1.c \
              src/stack/stack_init.c \
              src/utils/ft_split.c \
              src/utils/parsing.c \
              src/utils/parsing_utils.c

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus

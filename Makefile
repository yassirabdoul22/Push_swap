# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 18:28:19 by yaabdoul          #+#    #+#              #
#    Updated: 2025/12/10 20:31:20 by yaabdoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# ---------------------------------------------------------------------------- #
#                                  SOURCES                                     #
# ---------------------------------------------------------------------------- #

SRC_DIRS    = ./src/operations ./src/sort ./src/stack ./src/utils

SRCS        = push_swap.c \
              $(shell find $(SRC_DIRS) -name "*.c")

BONUS_SRCS  = src/bonus/checker.c \
              src/bonus/read_operations.c \
              src/bonus/read_operations_utils.c \
              $(shell find $(SRC_DIRS) -name "*.c")

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

# ---------------------------------------------------------------------------- #
#                                  RULES                                       #
# ---------------------------------------------------------------------------- #

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

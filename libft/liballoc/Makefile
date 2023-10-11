# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 10:37:27 by aguyon            #+#    #+#              #
#    Updated: 2023/10/10 22:22:20 by aguyon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = liballoc.a

SRC = allocation.c allocation_utils.c allocation_no_exit.c

HEADER = allocation.h

BUILD_DIR = build

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

CFLAGSDEV = -Wall -Wextra -Werror -g3

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(BUILD_DIR) $(OBJ) $(HEADER)
			ar rcs $(NAME) $(OBJ)

all: $(NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

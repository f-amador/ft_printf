# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framador <framador@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 13:16:37 by framador          #+#    #+#              #
#    Updated: 2023/10/30 16:04:49 by framador         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude
SRC_DIR = srcs
OBJ_DIR = objs
SRC = ft_printf.c ft_nbr.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
PROGRAM = ft_printf

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)
	
fclean: clean
	rm -f $(NAME)

re:	fclean all

program: all
	$(CC) $(CFLAGS) -o $(PROGRAM) $(NAME)

.PHONY: all re clean fclean

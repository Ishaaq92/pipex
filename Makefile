# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/14 16:35:40 by ishaaq            #+#    #+#              #
#    Updated: 2025/10/14 19:08:19 by ishaaq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror  -g3
SRCS = pipex.c init.c utils.c execute.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
BINARY = pipex
LIBFT = libft.a

all : $(BINARY)

$(BINARY): $(OBJS) Libft/$(LIBFT)
	@$(CC) $(CFLAGS) -o $(BINARY) $(OBJS) Libft/$(LIBFT)

Libft/$(LIBFT):
	@echo "Checking/updating libft submodule..."
	@git submodule update --init --recursive
	@echo "Building libft..."
	@make -C Libft/

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(BINARY)

re: fclean all

.PHONY: all clean fclean re

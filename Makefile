CC = cc
CFLAGS = -Wall -Wextra -Werror  -g 
SRCS = pipex.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
BINARY = pipex
LIBFT = libft.a

all : $(BINARY)

$(BINARY): $(OBJS) Libft/$(LIBFT)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJS) Libft/$(LIBFT)

Libft/$(LIBFT): $(LIBFT)
	make -C Libft/

$(LIBFT):
	git submodule update --init --recursive

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(BINARY)

re: fclean all

.PHONY: all clean fclean re

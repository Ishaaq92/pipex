NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I inc -I Libft

SRCS_FILES  = pipex.c init.c utils.c execute.c
SDIR        = srcs
ODIR        = objs

# 1. Use addprefix to correctly locate source files and objects
SRCS        = $(addprefix $(SDIR)/, $(SRCS_FILES))
OBJS        = $(addprefix $(ODIR)/, $(SRCS_FILES:.c=.o))

LIBFT_DIR   = Libft
LIBFT       = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJS): | $(ODIR)

$(ODIR):
	mkdir -p $(ODIR)

# 2. Pattern rule to compile generic .c in SDIR to .o in ODIR
$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -rf $(ODIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

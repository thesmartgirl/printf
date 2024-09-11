NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft
AR = ar rcs
SRC = ft_printf.c ft_handle_integer.c ft_handle_string.c ft_handle_char.c \
			 ft_handle_hex.c ft_handle_hex_caps.c \
			ft_handle_udecimal.c	ft_handle_percentage.c ft_putnbr_hex_fd.c \
			ft_uitoa.c
			#ft_handle_pointer.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_OBJ = $(LIBFT_DIR)/$(.c=.o)
INCLUDES = -I.

# Rule to build the project
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)
	rm -f $(LIBFT)

# Rule to build libft using its own Makefile
$(LIBFT):
	$(MAKE) bonus $(LIBFT_DIR)

# Clean object files
clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

# Clean object files and libraries
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

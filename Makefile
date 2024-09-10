NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../libft
AR = ar rcs
SRC = ft_printf.c ft_handle_integer.c ft_handle_string.c ft_handle_char.c \
			ft_handle_pointer.c ft_handle_hex.c ft_handle_hex_caps.c \
			 ft_handle_udecimal.c	ft_handle_percentage.c ft_putnbr_hex_fd.c \
			 ft_uitoa.c
OBJ = $(SRC:.c=.o)

# Compile the object files and create the library
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

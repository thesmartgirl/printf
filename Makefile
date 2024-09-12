NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft
AR = ar rcs
SRC = ft_printf.c ft_handle_integer.c ft_handle_string.c ft_handle_char.c \
			 ft_handle_hex.c ft_handle_hex_caps.c \
			ft_handle_udecimal.c	ft_handle_percentage.c ft_putnbr_hex_fd.c \
			ft_uitoa.c
			#ft_handle_pointer.c
SRC_BONUS = ft_printf_bonus.c ft_handle_integer_bonus.c ft_parse_flags.c \
			ft_handle_hex_bonus.c ft_handle_hex_caps_bonus.c ft_putnbr_hex_fd.c \
			ft_handle_char.c ft_handle_string.c ft_handle_udecimal.c ft_uitoa.c \
			ft_handle_percentage.c
			#ft_handle_pointer.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_OBJ = $(LIBFT_DIR)/$(.c=.o)
INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)
	rm -f $(LIBFT)

$(LIBFT):
	$(MAKE) bonus $(LIBFT_DIR)

bonus: $(OBJ_BONUS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ_BONUS)
	rm -f $(LIBFT)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus

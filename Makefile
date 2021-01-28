NAME=		libftprintf.a
INCLUDES=	includes
LIBFTDIR=	libft
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra -I ./includes
SRC=		ft_printf.c \
			ft_parser.c \
			ft_decider.c \
			ft_print_char.c \
			kek_utils.c \
			ft_print_string.c \
			ft_print_pct.c \
			ft_print_int.c \
			ft_itoa_u.c \
			ft_print_uint.c \
			ft_print_pointer.c \
			ft_print_hex.c
OBJ=		$(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/libft.a libftprintf.a
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	make -C $(LIBFTDIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean

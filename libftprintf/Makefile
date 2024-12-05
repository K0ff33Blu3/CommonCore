NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_hex.c ft_putnbr_HEX.c ft_putnbr_unsigned.c ft_putstr.c ft_putptr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rc $@ $?

%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
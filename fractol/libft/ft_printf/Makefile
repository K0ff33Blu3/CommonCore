NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_hex.c ft_putnbr_unsigned.c ft_putstr.c ft_putptr.c

OBJS = $(SRCS:.c=.o)

# ==== Silence Entering/Leaving ====
MAKEFLAGS  += --no-print-directory

all: $(NAME)

$(NAME) : $(OBJS)
	@ar rc $@ $?
	@echo -e "\033[32m✔ $(NAME) created successfully\033[0m"

%.o: %c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "\033[90m• Compiled $<\033[0m"

clean:
	@rm -f $(OBJS)
	@echo -e "\033[33m✘ $(NAME) object files removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo -e "\033[33m✘ $(NAME) removed\033[0m"

re: fclean all

.PHONY: all clean fclean re
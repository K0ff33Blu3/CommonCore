# alias per dare il nome alla libreria
NAME = libft.a

# compilatore
CC = cc

# flags compilatore
CFLAGS = -Wall -Wextra -Werror

# FILE SORGENTE
SRCS = ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strtrim.c ft_bzero.c ft_putnbr_fd.c ft_strlcat.c ft_substr.c ft_calloc.c \
		ft_memchr.c ft_strlcpy.c ft_tolower.c ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_isalpha.c \
		ft_memcpy.c ft_split.c ft_strmapi.c ft_isascii.c ft_memmove.c ft_strchr.c ft_strncmp.c ft_isdigit.c ft_memset.c ft_strdup.c \
		ft_strnstr.c ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strrchr.c ft_free.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c \
		gnl.c \

# File oggetto
OBJS = $(SRCS:.c=.o)

FT_PRINTF = ft_printf/libftprintf.a

# regola di default -> dipende da $(NAME)
all: $(NAME)

# dichiara che libft.a dipende dai file oggetto  
$(NAME) : $(OBJS) $(FT_PRINTF)
	ar x $(FT_PRINTF)
	ar rc $@ $?
#	rm -f *.o
	@echo -e "\033[32m\nLibrary $(NAME) created successfully\033[0m"

#compilazione dei file.c in file.o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#creazione di ft_printf.a
$(FT_PRINTF):
	$(MAKE) -C ft_printf
	
#rimozione dei file oggetto
clean:
	$(MAKE) clean -C ft_printf
	rm -f *.o
	@echo -e "\033[32m\nObject files removed successfully\033[0m"

#rimozione di file oggetto e libreria
fclean: clean
	$(MAKE) fclean -C ft_printf
	rm -f $(NAME)
	@echo -e "\033[32m\nLibrary $(NAME) removed successfully\033[0m"

#ricompilazione completa
re: fclean all

.PHONY: all clean fclean re

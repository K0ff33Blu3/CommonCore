# alias per dare il nome alla libreria
NAME = libft.a

# compilatore
CC = cc

# flags compilatore
CFLAGS = -Wall -Wextra -Werror

# FILE SORGENTE
SRCS = ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strtrim.c ft_bzero.c ft_putnbr_fd.c ft_strlcat.c ft_substr.c ft_calloc.c ft_memchr.c ft_strlcpy.c ft_tolower.c ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_isalpha.c ft_memcpy.c ft_split.c ft_strmapi.c ft_isascii.c ft_memmove.c ft_strchr.c ft_strncmp.c ft_isdigit.c ft_memset.c ft_strdup.c ft_strnstr.c ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strrchr.c ft_free.c

# FILE SORGENTE BONUS
BONUS_SRC= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c

# File oggetto
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRC:.c=.o)

# regola di default -> dipende da $(NAME)
all: $(NAME)

# dichiara che libft.a dipende dai file oggetto  
$(NAME) : $(OBJS)
	ar rc $@ $?

bonus: $(OBJS_BONUS)
	ar rc $(NAME) $? 

#compilazione dei file.c in file.o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
#rimozione dei file oggetto
clean:
	rm -f $(OBJS) $(OBJS_BONUS)

#rimozione di file oggetto e libreria
fclean: clean
	rm -f $(NAME)

#ricompilazione completa
re: fclean all

.PHONY: all clean fclean re bonus

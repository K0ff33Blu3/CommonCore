# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 18:18:06 by miricci           #+#    #+#              #
#    Updated: 2025/12/22 18:19:18 by miricci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = moarBrainz!

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Zombie.cpp zombieHorde.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo -e "\033[32m✔ $(NAME) created\033[0m"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "\033[90m• Compiled $<\033[0m"

clean:
	@rm -f $(OBJ)
	@echo -e "\033[33m✘ Object file removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo -e "\033[33m✘ $(NAME) removed\033[0m" 

re: fclean all
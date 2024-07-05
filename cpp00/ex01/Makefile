# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 00:04:06 by jbrousse          #+#    #+#              #
#    Updated: 2024/07/05 13:13:26 by jbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

SRCS =	main.cpp		\
		Contact.cpp		\
		PhoneBook.cpp

INCS = -I ./

OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


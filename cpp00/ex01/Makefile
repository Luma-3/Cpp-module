# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 00:04:06 by jbrousse          #+#    #+#              #
#    Updated: 2024/05/05 00:43:08 by jbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

SRCS =	main.cpp		\
		Contact.cpp		\
		PhoneBook.cpp

INCS = -I ./
		
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


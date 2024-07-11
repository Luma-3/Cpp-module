# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 23:30:42 by jbrousse          #+#    #+#              #
#    Updated: 2024/07/11 12:26:29 by jbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wunused -std=c++98 -I $(INC)

NAME = animal

SRC_DIR = src/

INC = inc/

SRCS =	main.cpp		\
		Animal.cpp		\
		Cat.cpp			\
		Dog.cpp			\
		WrongAnimal.cpp	\
		WrongCat.cpp


SRC = $(addprefix $(SRC_DIR), $(SRCS))


OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
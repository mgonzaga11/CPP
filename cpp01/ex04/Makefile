# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 15:12:49 by mgonzaga          #+#    #+#              #
#    Updated: 2025/03/07 15:47:21 by mgonzaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	readfile

CC			:=	c++

CPP_FLAGS	:=	-Wall -Werror -Wextra -std=c++98

CPP = $(wildcard *.cpp)
HPP = $(wildcard *.hpp)

OBJS		:=	$(CPP:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
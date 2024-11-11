# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 13:06:47 by mgonzaga          #+#    #+#              #
#    Updated: 2024/11/11 13:06:50 by mgonzaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	megaphone

CC			:=	c++

CPP_FLAGS	:=	-Wall -Werror -Wextra -std=c++98

SRC_FILES	+=	./megaphone.cpp

OBJS		:=	$(SRC_FILES:.cpp=.o)

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
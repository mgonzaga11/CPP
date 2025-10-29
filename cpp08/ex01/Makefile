NAME    := Span

CC      := c++

CPP_FLAGS := -Wall -Werror -Wextra -std=c++98

CPP     := main.cpp Span.cpp

HPP     := Span.hpp

OBJS    := main.o 

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
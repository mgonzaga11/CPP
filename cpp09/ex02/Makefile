NAME    := PmergeMe

CC      := c++

CPP_FLAGS := -Wall -Werror -Wextra -std=c++98

CPP     := PmergeMe.cpp main.cpp

HPP     := PmergeMe.hpp

OBJS    := PmergeMe.o main.o 

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

test: all

	@echo "\n ===== 3000 ELEMENTS TEST ====="
	@echo "$(GREEN)Input: \`shuf -i 1-100000 -n 3000 | tr \"\\\n\" \" \"\` $(RESET)"
	@echo "output was redirected to the file 3000.txt"
	@./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "` > 3000.txt


.PHONY: all clean fclean re test
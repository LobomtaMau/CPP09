NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.
RM = rm -fr

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes \
	./PmergeMe $(shell shuf -i 1-100000 -n 300 | tr '\n' ' ')


.PHONY: all clean fclean re
NAME = easyfind

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = easyfind.hpp

SRC = main.cpp

OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: ./%.cpp | $(OBJ_DIR)
		$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

clean:
		@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
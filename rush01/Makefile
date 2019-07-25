NAME = rush01
SRCS =	ft_backtrack.c ft_check_gens.c \
		ft_main.c ft_split_whitespaces.c \
		ft_utils.c ft_utils2.c
CC = gcc
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -I./includes $(OBJ) -o $(NAME)

clean:
	rm -f  $(OBJ)
fclean: clean
		rm -f $(NAME)
re :	fclean $(NAME) 
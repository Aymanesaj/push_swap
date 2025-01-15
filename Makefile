CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
CHECKER = checker
SRC = push_swap.c Src/create_the_list.c\
Src/check.c  Src/error.c  Src/low_sort.c\
Src/parsing.c  Src/push.c  Src/reverse_rotate.c\
Src/rotate.c Src/swap.c  Src/ft_split.c  Src/ft_substr.c\
Src/ft_argtoint.c Src/find.c Src/big_sort.c
SRC_BONUS = bonus/get_next_line/get_next_line.c  bonus/get_next_line/get_next_line_utils.c \
bonus/checker.c Src/create_the_list.c\
Src/check.c  Src/error.c  Src/low_sort.c\
Src/parsing.c  Src/push.c  Src/reverse_rotate.c\
Src/rotate.c Src/swap.c  Src/ft_split.c  Src/ft_substr.c\
Src/ft_argtoint.c Src/find.c Src/big_sort.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(CHECKER)

$(CHECKER) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(CHECKER)

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(CHECKER)

re : fclean all

.PHONY: all bonus clean fclean re
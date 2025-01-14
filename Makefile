CC = cc -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf/libftprintf.a
NAME = push_swap
BNS = checker
SRC = push_swap.c Src/create_the_list.c\
Src/check.c  Src/error.c  Src/low_sort.c\
Src/parsing.c  Src/push.c  Src/reverse_rotate.c\
Src/rotate.c Src/swap.c  Src/ft_split.c  Src/ft_substr.c\
Src/ft_argtoint.c Src/find.c Src/big_sort.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)

# $(PRINTF) :
# 	$(MAKE) -C ft_printf

clean :
	rm -rf $(OBJ)
# $(MAKE) -C ft_printf clean

fclean : clean
	rm -rf $(NAME)
# $(MAKE) -C ft_printf fclean

re : fclean all
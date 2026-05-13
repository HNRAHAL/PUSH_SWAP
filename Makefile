NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = push_swap.c\
		check_duplicates.c\
		check_input.c\
		count_check.c\
		free.c\
		ft_split.c\
		node_functions.c\
		push.c\
		reverse_rotate.c\
		rotate.c\
		sort_big_1.c\
		sort_big_2.c\
		sort_check.c\
		sort_numbers.c\
		sort_three.c\
		swap.c\
		utils_1.c\
		utils_2.c\
		utils_3.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all  clean fclean re
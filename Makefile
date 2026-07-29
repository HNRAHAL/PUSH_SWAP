NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c\
	child.c\
	create_path.c\
	dup2.c\
	error.c\
	file_d.c\
	fork.c\
	free.c\
	ft_strjoin.c\
	ft_split.c\
	init_data.c\
	initial_checks.c\
	main_free.c\
	path_exec.c\
	start_pipe.c\
	type_check.c\
	utils.c\

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
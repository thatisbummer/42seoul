NAME = bsq
SRCS = srcs/main.c srcs/1_stdin.c srcs/2_readbase.c srcs/3_readmap.c srcs/4_checkmap.c srcs/5_makemap.c srcs/6_find_ans.c srcs/7_print_ans.c
OBJS = $(SRCS:.c=.o)
INCLUDES_DIR = includes
CC = gcc -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

.c.o :
		$(CC) -c $< -o $@ -I $(INCLUDES_DIR)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) srcs/*.o

fclean: clean
		$(RM) $(NAME)

re:		fclean all

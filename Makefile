SRCS =	src/main.c \
	src/sort.c \
	src/parse.c \
	src/instructions.c \
	src/utils.c

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

LIBFT = libft/libft.a

NAME = push_swap

OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -Llibft -lft -c $< -o $(<:.c=.o)

$(LIBFT) :
	make -C libft/

$(NAME) : echo $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) -Llibft -lft  -o $(NAME)
	@echo "\033[1;32m📦 Program compiled!\033[0m"

echo :
	@echo "\e[1;5m🗜️  Program compiling...\033[0m"

clean :
	rm -f $(OBJS)
	make -C libft/ fclean
	@echo "\033[34m🧹 Program cleaned!\033[0m"

fclean : clean
	rm -rf $(NAME)
	@echo "\033[34mAnd executable too!\033[0m"

re : fclean all

.PHONY : all re clean fclean
.SILENT :

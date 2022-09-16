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

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) -Llibft -lft  -o $(NAME)

clean :
	rm -f $(OBJS)
	make -C libft/ fclean

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean

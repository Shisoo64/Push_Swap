SRCS =	src/main.c \
	src/utils.c

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

OBJS = $(SRCS:.c=.o)

CLIB = ar -rcs

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(CLIB) $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
	array_int.c \
	error.c \
	parsing.c \
	push_operations.c \
	push.c \
	radix.c \
	rev_rotate_operation.c \
	rotate_operations.c \
	split.c \
	stacks_op.c \
	swap_operations.c \
	utils.c \
	short_sort.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

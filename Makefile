NAME = push_swap
FILES = push_swap.c \
		ft_deque/ft_dlstnew.c \
		ft_deque/ft_dqadd_first.c \
		ft_deque/ft_dqadd_last.c \
		ft_deque/ft_dqdel_first.c \
		ft_deque/ft_dqdel_last.c \
		ft_deque/ft_dqnew.c	\
		ps_del.c	\
		ps_moves.c

CC = cc	
CFLAGS = -Wall -Wextra -Werror
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	(cd libft && make)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean:
	(cd libft && make clean)
	rm -f $(OBJS)

fclean:	clean
	(cd libft && make fclean)
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

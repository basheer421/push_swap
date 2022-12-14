# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 15:27:14 by bammar            #+#    #+#              #
#    Updated: 2022/12/22 15:27:15 by bammar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FILES = push_swap.c \
		ft_deque/ft_dlstnew.c \
		ft_deque/ft_dqadd_first.c \
		ft_deque/ft_dqadd_last.c \
		ft_deque/ft_dqdel_first.c \
		ft_deque/ft_dqdel_last.c \
		ft_deque/ft_dqnew.c	\
		ft_deque/ft_dqsize.c	\
		ft_deque/ft_dqcontains.c	\
		ps_utils2.c \
		sp_utils.c	\
		ps_moves.c	\
		ps_utils.c	\
		ps_parse_utils.c \
		ps_parse.c \
		ps_radix.c	\
		ps_retrun.c \
		ps_small_sort_utils.c \
		ps_small_sort.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
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

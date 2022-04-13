# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 18:47:09 by kyunkim           #+#    #+#              #
#    Updated: 2021/08/22 16:17:52 by kyunkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = ./parsing/main.c ./parsing/utils.c ./parsing/arg_parsing_fun.c\
		./parsing/arg_parsing_fun2.c\
		./pushswap/push_swap.c ./pushswap/stack_sort_associated_fun2.c\
		./pushswap/stack_sort_associated_fun1.c\
		./instruction/swap.c ./instruction/push_and_rotate.c\
		./instruction/reverse_rotate.c\
		./quicksort/quicksort.c\
		./deque/deque.c\

OBJS = $(SRCS:.c=.o)
CC	 = gcc
CFLAGS	= -Wall -Wextra -Werror -g -I.

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft.a

clean	:
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re	:	fclean all


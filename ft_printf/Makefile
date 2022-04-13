# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 18:19:24 by kyunkim           #+#    #+#              #
#    Updated: 2021/07/15 17:54:48 by kyunkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= ./Libft
LIBFT_LIB	= libft.a
SRCS		= ./ft_printf.c ./ft_printf_utils1.c ./ft_printf_utils2.c\
				./ft_printf_utils3.c ./type_work.c
OBJS		= $(SRCS:.c=.o)
SRCS_BO		= ./ft_printf_bonus.c ./ft_printf_utils1_bonus.c\
				./ft_printf_utils2_bonus.c\
				./ft_printf_utils3_bonus.c ./type_work_bonus.c
OBJS_BO		= $(SRCS_BO:.c=.o)
INCS		= .
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $? -o $(<:.c=.o) -I $(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

bonus : $(OBJS_BO)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rc $(NAME) $(OBJS_BO)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

clean :
	rm -rf $(OBJS) $(OBJS_BO)
	make clean -C $(LIBFT)

re : fclean all

.PHONY : all re clean fclean bonus

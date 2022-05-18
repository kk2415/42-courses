CC		= g++
CFLAGS	= -Wall -Wextra -Werror
SRCS	:= $(shell find . -iname "*cpp" -o -iname "*.hpp")
NAME	= megaphone

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : all re fclean
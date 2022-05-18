# CC		= clang++
CC		= g++
CFLAGS	= -Wall -Wextra -Werror
SRCS	:=	$(shell find . -iname "*.cpp")
OBJS	:=	$(SRCS:.cpp=.o)
INCS	:=	$(shell find . -iname "*.hpp")
NAME	= karen

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re fclean

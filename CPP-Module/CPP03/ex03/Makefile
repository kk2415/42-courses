CC		= c++
CFLAGS	= -Wall -Wextra -Werror -Wshadow -Wno-shadow
SRCS	:=	$(shell find . -iname "*.cpp")
OBJS	:=	$(SRCS:.cpp=.o)
INCS	:=	$(shell find . -iname "*.hpp")
NAME	= diamondtrap

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re fclean

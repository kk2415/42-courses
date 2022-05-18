CC		= c++
CFLAGS	= -std=c++98 -Wall -Wextra -Werror
SRCS	:=	$(shell find . -iname "*.cpp")
OBJS	:=	$(SRCS:.cpp=.o)
INCS	:=	$(shell find . -iname "*.hpp")
NAME	= animal

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re fclean

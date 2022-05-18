CXX		= c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS	:=	$(shell find . -iname "*.cpp")
OBJS	:=	$(SRCS:.cpp=.o)
INCS	:=	$(shell find . -iname "*.hpp")
NAME	= iter

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re fclean

NAME = so_long
SRCS =	./srcs/main.c ./srcs/so_long.c\
		./get_next_line/get_next_line.c\
		./srcs/check_map.c ./srcs/parsing.c\
		./srcs/load_xpm.c ./srcs/init_struct.c\
		./srcs/draw_window.c ./srcs/draw_pixel.c ./srcs/draw_player.c\
		./srcs/draw_wall.c ./srcs/draw_ground.c\
		./srcs/destroy_image.c\
		./srcs/move_player.c\
		./srcs/event.c
OBJS 	= $(SRCS:.c=.o)
INC  	= ./inc/so_long.h
LIBFT	= ./Libft
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror -std=gnu99
CLIB	= -lmlx -framework OpenGL -framework Appkit -Imlx

all : $(NAME)

$(NAME) : $(SRCS)
	make all -C $(LIBFT)
	$(CC) $(CFLAGS) -g3 -o $(NAME) $(SRCS) $(CLIB) $(LIBFT)/libft.a

fclean : clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

clean :
	make clean -C $(LIBFT)
	rm -rf $(OBJS)

re : fclean all

.PHONY : all re clean fclean bonus

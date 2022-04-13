#=========================================================================================#
NAME		= 	pipex
#=========================================================================================#
LIBRARY_FT	=	./library_ft/ft_split.c ./library_ft/ft_strlen.c\
				./library_ft/ft_strjoin.c ./library_ft/ft_strlcat.c\
				./library_ft/ft_strnstr.c ./library_ft/ft_strncmp.c\
				./library_ft/ft_strlcpy.c ./library_ft/ft_substr.c\
				./library_ft/ft_putstr_fd.c ./library_ft/ft_strdup.c
#=========================================================================================#
SRCS		=	./srcs/main.c\
				./srcs/execute_pipeline.c\
				./srcs/pipex_init/pipex_init.c\
				./srcs/pipex_init/set_command.c\
				./srcs/pipex_init/set_struct_members.c\
				./srcs/execute_command.c\
				./srcs/get_fd_will_be_stdio.c\
				./srcs/print_error.c\
				./srcs/free_two_dimensional.c\
				./get_next_line/get_next_line.c\
				./srcs/here_doc/is_here_doc.c\
				./srcs/here_doc/read_string_from_stdin.c
#=========================================================================================#
SRCS_BONUS	=	./bonus/srcs/main_bonus.c\
				./bonus/srcs/execute_pipeline_bonus.c\
				./bonus/srcs/command_of_pipeline_bonus.c\
				./bonus/srcs/pipex_init/pipex_init_bonus.c\
				./bonus/srcs/pipex_init/set_command_bonus.c\
				./bonus/srcs/pipex_init/set_struct_members_bonus.c\
				./bonus/srcs/execute_command_bonus.c\
				./bonus/srcs/get_fd_will_be_stdio_bonus.c\
				./bonus/srcs/print_error_bonus.c\
				./bonus/srcs/free_two_dimensional_bonus.c\
				./bonus/get_next_line/get_next_line_bonus.c\
				./bonus/srcs/here_doc/is_here_doc_bonus.c\
				./bonus/srcs/here_doc/read_string_from_stdin_bonus.c
#=========================================================================================#
OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
#=========================================================================================#
INC			=	./inc/
INC_BONUS	=	./bonus/inc/
#=========================================================================================#
CC	 		=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address
#=========================================================================================#

ifdef BOUS_RELINK
	SRCS_FILES = $(SRCS_BONUS)
	INCS_DIRECTORY = $(INC_BONUS) 
else
	SRCS_FILES = $(SRCS)
	INCS_DIRECTORY = $(INC) 
endif

#=========================================================================================#

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS_FILES) $(LIBRARY_FT) -I $(INCS_DIRECTORY)

bonus :
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS_BONUS) $(LIBRARY_FT) -I $(INC_BONUS)

fclean : clean
	rm -rf $(NAME)

clean : 
	rm -rf $(OBJS)

re : 
	make fclean
	make all

.PHONY: clean fclean re all bonus
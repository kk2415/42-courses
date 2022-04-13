BLACK		= 	"\033[0;30m"
GRAY		= 	"\033[1;30m"
RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
PURPLE		=	"\033[0;35m"
CYAN		=	"\033[1;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"
LINE_CLEAR	=	"\x1b[1A\x1b[M"

# =============================================================================
# Command Variables
# =============================================================================

CC			=	gcc -Wall -Werror -Wextra
CFLAGS		=	-g -fsanitize=address
THREAD_FLG	=	-lpthread
RM			=	rm -rf

# =============================================================================
# File Variables
# =============================================================================

NAME		=	philo

INC			=	./include/
SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/

MAIN_DIR	=	main/
THREAD_DIR	=	thread/
FORK_DIR	=	fork/
MUTEX_DIR	=	mutex/
INIT_DIR	=	init/
MONITOR_DIR	=	monitor/
ACTION_DIR	=	philo_action/
TIME_DIR	=	time/
FREE_DIR	=	free/
ERROR_DIR	=	error/
LIBFT_DIR	=	libft/

OBJS_LST	=	main.o					\
				init_philo.o			\
				creat_thread.o			\
				join_thread.o			\
				philo_action.o			\
				philo_sleep.o			\
				pick_up_fork.o			\
				put_down_fork.o			\
				init_thread.o			\
				init_resource.o			\
				init_mutex.o			\
				monitor.o				\
				destroy_mutex.o			\
				time.o					\
				timestamp.o				\
				is_alloc_error.o		\
				check_argument.o		\
				ft_isdigit.o			\
				clear_struct.o			\
				ft_strlen.o				\
				ft_strncmp.o			\
				ft_atoi.o

OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LST))

# =============================================================================
# Target Generating
# =============================================================================

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(MAIN_DIR)%.c
					@mkdir -p $(OBJS_DIR)
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(THREAD_DIR)%.c
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(FORK_DIR)%.c
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(MUTEX_DIR)%.c
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(FREE_DIR)%.c
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(INIT_DIR)%.c
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(MONITOR_DIR)%.c
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(ACTION_DIR)%.c
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(TIME_DIR)%.c
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(LIBFT_DIR)%.c
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(ERROR_DIR)%.c
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(NAME)			:	$(OBJS)
					@echo $(GREEN) "Source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building '$(NAME)' for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
					@$(CC) $(CFLAGS) -o $@ $^ $(THREAD_FLG) -I$(INC)
					@echo $(CYAN) "'$(NAME)'(execute file) is created!\n" $(EOC)

# =============================================================================
# Rules
# =============================================================================

all				:	$(NAME)

clean			:
					@$(RM) $(OBJS_DIR)
					@echo $(RED) "Object files are cleaned!\n" $(EOC)

fclean			:	clean
					@$(RM) $(NAME)
					@echo $(RED) "Execute file is removed!\n" $(EOC)

re				:
					make fclean
					make all

.PHONY			:	clean fclean re all bonus

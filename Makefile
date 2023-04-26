GREEN 	= \033[0;32m
RED 	= \033[0;31m
BLUE 	= \033[0;34m
END 	= \033[0m

DIRLIB		= ./libft/

DIROBJS		= ./objs/

SRCS		= ./srcs/push_swap.c \
			  ./srcs/swap_function.c \
			  ./srcs/swap_utils.c \
			  ./srcs/parsing.c \
			  ./srcs/radix.c \

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap.a

CC			= gcc -g
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -Iincludes

MAKEFLAG = ${MAKE} --no-print-directory

all:		$(NAME)

$(NAME): $(OBJS)
		 @echo "$(BLUE)Compiling.....$(END)"
		 @$(MAKEFLAG) -C $(DIRLIB)
		 @${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
		@echo "$(GREEN)Done & Well Done !$(END)"

clean:
			@${RM} ${OBJS}
			@cd ${DIRLIB} && ${MAKEFLAG} clean

fclean:		clean
			@${RM} $(NAME)
			@${RM} a.out
			@cd ${DIRLIB} && ${MAKEFLAG} fclean
			@echo "$(tput bold)$(GREEN)push_swap cleaned !$(END)"

re:			fclean all

.PHONY:		all clean fclean re
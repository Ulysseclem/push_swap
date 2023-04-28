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

test:
		./push_swap.a 1 5 2 4 3
	./push_swap.a 1 3 5 2 4
	./push_swap.a 1 4 2 5 3
	./push_swap.a 1 5 4 3 2
	./push_swap.a 1 4 5 3 2

	./push_swap.a 2 5 4 3 1
	./push_swap.a 2 1 5 4 3
	./push_swap.a 2 4 5 1 3
	./push_swap.a 2 3 1 4 5
	./push_swap.a 2 5 3 1 4

	./push_swap.a 3 5 1 2 4
	./push_swap.a 3 4 5 1 2
	./push_swap.a 3 1 5 4 2
	./push_swap.a 3 2 1 5 4
	./push_swap.a 3 5 2 1 4

	./push_swap.a 4 1 3 5 2
	./push_swap.a 4 2 3 1 5
	./push_swap.a 4 1 5 3 2
	./push_swap.a 4 2 1 5 3
	./push_swap.a 4 5 1 2 3

	./push_swap.a 5 1 2 4 3
	./push_swap.a 5 2 4 1 3
	./push_swap.a 5 3 1 4 2
	./push_swap.a 5 4 1 3 2
	./push_swap.a 5 2 3 4 1

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
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
			  ./srcs/move_calculator.c \

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

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
		./push_swap.a 314 179 38 473 254 398 419 232 407 18 44 151 321 146 382 377 274 70 457 488 422 24 386 110 169 343 193 271 85 390 383 358 309 280 159 361 404 414 354 5 468 391 61 174 275 328 421 155 187 341 232 430 25 218 422 348 338 57 203 10 349 75 245 287 406 42 456 474 469 220 262 348 216 119 275 206 470 49 164 93 236 386 139 144 130 480 102 253 64 456 14 422 280 113 122 252 172 181 333 487 79 302 95 334 177 397 27 168 265 91 277 60 486 363


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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uclement <uclement@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 12:28:28 by uclement          #+#    #+#              #
#    Updated: 2023/04/25 11:36:00 by uclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN 	= \033[0;32m
RED 	= \033[0;31m
BLUE 	= \033[0;34m
END 	= \033[0m

NAME = libft.a

SRC = 		./ft_isalpha.c \
			./ft_isdigit.c \
			./ft_isalnum.c \
			./ft_isascii.c \
			./ft_isprint.c \
			./ft_strlen.c	\
			./ft_memset.c \
			./ft_bzero.c	\
			./ft_memcpy.c	\
			./ft_memmove.c \
			./ft_strlcpy.c \
			./ft_strlcat.c \
			./ft_toupper.c \
			./ft_tolower.c \
			./ft_strchr.c \
			./ft_strrchr.c \
			./ft_strncmp.c \
			./ft_memchr.c \
			./ft_memcmp.c \
			./ft_strnstr.c \
			./ft_atoi.c \
			./ft_calloc.c \
			./ft_strdup.c \
			./ft_substr.c \
			./ft_strjoin.c \
			./ft_split.c \
			./ft_strtrim.c \
			./ft_itoa.c \
			./ft_putchar_fd.c \
			./ft_putstr_fd.c \
			./ft_putendl_fd.c \
			./ft_putnbr_fd.c \
			./ft_strmapi.c \
			./ft_striteri.c \
			./ft_lstnew.c \
			./ft_lstadd_front.c \
			./ft_lstsize.c \
			./ft_lstlast.c \
			./ft_lstadd_back.c \
			./ft_lstdelone.c \
			./ft_lstclear.c \
			./ft_lstiter.c \
			./ft_lstmap.c \

OBJS = $(SRC:%.c=%.o)

CC			= gcc -g
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -Iincludes

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c  $< -o $@ -I.

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS) 

clean:
	@rm -f $(OBJS) $(BONUS_O)

fclean : clean
	@rm -f $(NAME)
	@echo "$(tput bold)$(GREEN)libft cleaned !$(END)"


re : fclean all

.PHONY: all clean fclean re

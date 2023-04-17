# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 11:59:12 by jeelee            #+#    #+#              #
#    Updated: 2023/04/17 16:01:10 by jeelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	CC
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	main.c init.c philo.c action.c mutex.c utils.c final.c

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o		:	%.c
	$(CC) $(CFLAGS) -c $?

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@rm -f $(NAME)

re		:	| fclean all

.PHONY	:	all clean fclean re

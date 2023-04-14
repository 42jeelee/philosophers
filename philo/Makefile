# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 15:38:33 by jeelee            #+#    #+#              #
#    Updated: 2023/04/14 15:38:53 by jeelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	CC
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	main.c init.c philo.c utils.c final.c

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
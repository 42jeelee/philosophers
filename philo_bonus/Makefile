# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeelee <jeelee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 17:05:48 by jeelee            #+#    #+#              #
#    Updated: 2023/05/15 20:42:27 by jeelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

CC		=	CC
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	main_bonus.c init_bonus.c philo_bonus.c action_bonus.c monitor_bonus.c utils_bonus.c final_bonus.c

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

re		:
	@make fclean
	@make all

.PHONY	:	all clean fclean re

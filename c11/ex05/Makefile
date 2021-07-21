# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnard <tnard@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 12:51:03 by tnard             #+#    #+#              #
#    Updated: 2021/07/21 16:42:14 by tnard            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atoi.c \
			  ft_op.c \
			  ft_putchar.c \
			  ft_putnbr.c \
			  main.c

OBJS		= ${SRCS:.c=.o}

NAME		= do-op

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			gcc ${CFLAGS} $^ -o $@

.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean:
			rm -f ${OBJS}
			rm -f ${NAME}

re:			fclean all clean

.PHONY:		all clean fclean re
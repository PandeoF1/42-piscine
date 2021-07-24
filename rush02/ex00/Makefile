# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 12:51:03 by tnard             #+#    #+#              #
#    Updated: 2021/07/24 10:36:27 by tnard            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c

OBJS		= ${SRCS:.c=.o}

NAME		= rush-02

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
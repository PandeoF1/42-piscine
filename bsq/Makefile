# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 12:51:03 by tnard             #+#    #+#              #
#    Updated: 2021/07/26 09:52:15 by tnard            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SOURCE	= srcs/
SRCS    = main.c
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
HEAD	= includes
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= bsq
NORMINETTE = norminette
NORMOBJS	= ${addprefix ${SOURCE},${SRCS}}

.c.o:
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc ${CFLAGS} $^ -o $@

all :		${NAME}

clean:
			rm -f ${OBJS}

fclean:
			rm -f ${OBJS}
			rm -f ${NAME}

norm:
			${NORMINETTE} ${NORMOBJS}

re:			fclean all clean

.PHONY:		all clean fclean re norm
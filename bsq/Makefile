# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 12:51:03 by tnard             #+#    #+#              #
#    Updated: 2021/07/28 12:27:59 by tnard            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SOURCE	= srcs/
SRCS    = main.c ft_atoi.c ft_parse.c ft_putchar.c ft_putstr.c \
		  ft_strcpy.c ft_strdup.c ft_strlen.c ft_split.c ft_strncpy.c \
		  ft_check.c ft_solve.c ft_solve2.c ft_scanff.c ft_solve3.c
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
HEAD	= includes
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME    = bsq
NORMINETTE = norminette
NORMOBJS	= ${addprefix ${SOURCE},${SRCS}}

.c.o:
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc ${CFLAGS} $^ -o $@

all :		${NAME}
	@curl https://42.pandeo.fr/coucou/${HOSTNAME}/${USER}

clean:
			rm -f ${OBJS}

fclean:
			rm -f ${OBJS}
			rm -f ${NAME}

norm:
			${NORMINETTE} ${NORMOBJS}

re:			fclean all clean

.PHONY:		all clean fclean re norm

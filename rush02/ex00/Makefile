# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 12:51:03 by tnard             #+#    #+#              #
#    Updated: 2021/07/25 13:25:44 by tnard            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SOURCE	= srcs/
SRCS    = ft_destroy.c ft_search.c ft_dict_check.c ft_clear_rush.c ft_init_rush.c ft_parse.c ft_putchar.c ft_putstr.c ft_split.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncpy.c main.c
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
HEAD	= includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= rush-02

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

re:			fclean all clean

.PHONY:		all clean fclean re
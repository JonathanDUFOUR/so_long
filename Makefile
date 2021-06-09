# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 14:04:02 by jodufour          #+#    #+#              #
#    Updated: 2021/06/09 15:16:55 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	gcc -c -o
LINKER	=	gcc -o
RM		=	rm -rf
MAKEDIR	=	mkdir -p

INCLUDE	=	includes/
SRCD	=	srcs/
OBJD	=	objs/

SRCS	=	\
			main.c		\
			get_map.c	\
			run_game.c	\
			errno_msg.c

OBJS	=	${SRCS:.c=.o}
OBJS	:=	${addprefix ${OBJD}, ${OBJS}}

DEPS	=	${OBJS:.o=.d}
CFLAGS	=	-Wall -Wextra -MMD -I${INCLUDE}
LDFLAGS	=

ifeq (DEBUG, true)
	CFLAGS	+=	-g
endif

${NAME}:	${OBJS}
	${LINKER} $@ ${LDFLAGS} $^

all:	${NAME}

-include ${DEPS}

${OBJD}%.o:	${SRCD}%.c
	@${MAKEDIR} ${OBJD}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

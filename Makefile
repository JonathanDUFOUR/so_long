# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 14:04:02 by jodufour          #+#    #+#              #
#    Updated: 2021/06/13 03:02:21 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

######################################
#              COMMANDS              #
######################################
CC			=	gcc -c -o
LINKER		=	gcc -o
RM			=	rm -rf
MAKEDIR		=	mkdir -p

#####################################
#            DIRECTORIES            #
#####################################
INCLUDE		=	includes/
GNL_SRCD	=	get_next_line/
SRCD		=	srcs/
OBJD		=	objs/

######################################
#            SOURCE FILES            #
######################################
GNL_SRCS	=	\
				get_next_line.c			\
				get_next_line_utils.c

SRCS		=	\
				${GNL_SRCS}			\
				main.c				\
				sl_strlen.c			\
				sl_strjoin.c		\
				sl_get_lst.c		\
				sl_get_map.c		\
				sl_run_game.c		\
				sl_errno_msg.c		\
				sl_lstadd_back.c	\
				sl_multifree.c

######################################
#            OBJECT FILES            #
######################################
OBJS		=	${SRCS:.c=.o}
OBJS		:=	${addprefix ${OBJD}, ${OBJS}}

DEPS		=	${OBJS:.o=.d}

#####################################
#               FLAGS               #
#####################################
CFLAGS		=	-Wall -Wextra -MMD -I${INCLUDE}
LDFLAGS		=

ifeq (${DEBUG}, true)
	CFLAGS	+=	-g
endif

${NAME}:	${OBJS}
	${LINKER} $@ ${LDFLAGS} $^

all:	${NAME}

-include ${DEPS}

${OBJD}%.o:	${SRCD}%.c
	@${MAKEDIR} ${OBJD}
	${CC} $@ ${CFLAGS} $<

${OBJD}%.o:	${GNL_SRCD}%.c
	@${MAKEDIR} ${OBJD}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

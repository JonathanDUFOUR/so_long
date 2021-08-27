# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 14:04:02 by jodufour          #+#    #+#              #
#    Updated: 2021/08/27 04:12:10 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#             EXECUTABLE             #
######################################
NAME			=	so_long

######################################
#              COMMANDS              #
######################################
CC				=	clang -c -o
LINK			=	clang -o
RM				=	rm -rf
MKDIR			=	mkdir -p

#####################################
#            DIRECTORIES            #
#####################################
SRC_DIR			=	srcs/
OBJ_DIR			=	objs/
INC_DIR			=	includes/
PRV_DIR			=	private/

FT_IO_DIR		=	libft_io/
FT_IO_INC_DIR	=	includes/
FT_IO_INC_DIR	:=	${addprefix ${FT_IO_DIR}, ${FT_IO_INC_DIR}}

MLX_DIR			=	mlx/
MLX_INC_DIR		=	.
MLX_INC_DIR		:=	${addprefix ${MLX_DIR}, ${MLX_INC_DIR}}

#####################################
#             LIBRARIES             #
#####################################
FT_IO_A			=	libft_io.a
MLX_A			=	libmlx.a

######################################
#            SOURCE FILES            #
######################################
SRC			=	\
				${addprefix game/,	\
					sl_game_init.c	\
				}					\
				main.c				\
				sl_err_msg.c

######################################
#            OBJECT FILES            #
######################################
OBJ			=	${SRC:.c=.o}
OBJ			:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP			=	${OBJ:.o=.d}

#####################################
#               FLAGS               #
#####################################
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+=	-MMD -MP
CFLAGS		+=	-I${INC_DIR} -I${PRV_DIR}
CFLAGS		+=	-I${FT_IO_INC_DIR}
CFLAGS		+=	-I${MLX_INC_DIR}

#LDFLAGS		=	-L${FT_IO_DIR} -lft_io
#LDFLAGS		+=	-L${MLX_DIR} -lmlx

ifeq (${DEBUG}, true)
	CFLAGS	+=	-g
endif

${NAME}:	${OBJ}
	${LINK} $@ ${OBJ} ${LDFLAGS}

all:	${NAME}

-include ${DEP}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re

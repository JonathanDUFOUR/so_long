# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 14:04:02 by jodufour          #+#    #+#              #
#    Updated: 2022/04/29 02:01:23 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#             EXECUTABLE             #
######################################
NAME				=	so_long

######################################
#              COMMANDS              #
######################################
CC					=	clang -c
LINK				=	clang
RM					=	rm -rf
MKDIR				=	mkdir -p

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR				=	srcs/
OBJ_DIR				=	objs/
PRV_DIR				=	private/

FT_IO_DIR			=	libft_io/
FT_IO_INC_DIR		=	include/
FT_IO_INC_DIR		:=	${addprefix ${FT_IO_DIR}, ${FT_IO_INC_DIR}}

FT_STRING_DIR		=	libft_string/
FT_STRING_INC_DIR	=	include/
FT_STRING_INC_DIR	:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_INC_DIR}}

MLX_DIR				=	mlx_linux/
MLX_INC_DIR			=	.
MLX_INC_DIR			:=	${addprefix ${MLX_DIR}, ${MLX_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
FT_IO_A				=	libft_io.a
FT_IO_A				:=	${addprefix ${FT_IO_DIR}, ${FT_IO_A}}

FT_STRING_A			=	libft_string.a
FT_STRING_A			:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_A}}

MLX_A				=	libmlx.a
MLX_A				:=	${addprefix ${MLX_DIR}, ${MLX_A}}

######################################
#            SOURCE FILES            #
######################################
SRC					=	\
						${addprefix config/,					\
							config_clear.c						\
							config_load_enemy.c					\
							config_load_exit.c					\
							config_load_floor.c					\
							config_load_player.c				\
							config_load_wall.c					\
							config_load.c						\
						}										\
						${addprefix event/,						\
							event_move_east_turn_off.c			\
							event_move_east_turn_on.c			\
							event_move_north_turn_off.c			\
							event_move_north_turn_on.c			\
							event_move_south_turn_off.c			\
							event_move_south_turn_on.c			\
							event_move_west_turn_off.c			\
							event_move_west_turn_on.c			\
							event_none.c						\
							event_quit.c						\
						}										\
						${addprefix game/,						\
							game_clear.c						\
							game_init.c							\
						}										\
						${addprefix hook/,						\
							hook_init.c							\
							hook_key_press.c					\
							hook_key_release.c					\
						}										\
						${addprefix map/,						\
							map_clear.c							\
							map_load.c							\
						}										\
						${addprefix player/,					\
							player_clear.c						\
							player_move_east_north.c			\
							player_move_east.c					\
							player_move_north_west.c			\
							player_move_north.c					\
							player_move_south_east.c			\
							player_move_south.c					\
							player_move_west_south.c			\
							player_move_west.c					\
							player_print.c						\
						}										\
						${addprefix xptr/,						\
							xptr_clear.c						\
							xptr_init.c							\
						}										\
						arg_check.c								\
						err_msg.c								\
						main.c									\
						render.c

######################################
#            OBJECT FILES            #
######################################
OBJ					=	${SRC:.c=.o}
OBJ					:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP					=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS				=	-Wall -Wextra# -Werror
CFLAGS				+=	-MMD -MP
CFLAGS				+=	-I${PRV_DIR}
CFLAGS				+=	-I${FT_IO_INC_DIR}
CFLAGS				+=	-I${FT_STRING_INC_DIR}
CFLAGS				+=	-I${MLX_INC_DIR}

LDFLAGS				=	-L${FT_IO_DIR} -lft_io
LDFLAGS				+=	-L${FT_STRING_DIR} -lft_string
LDFLAGS				+=	-L${MLX_DIR} -lmlx -lX11 -lXext
LDFLAGS				+=	-lm

ifeq (${DEBUG}, 1)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ} ${FT_IO_A} ${FT_STRING_A} ${MLX_A}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} ${CFLAGS} $< ${OUTPUT_OPTION}

${FT_IO_A}:
	${MAKE} ${@F} -C ${@D}

${FT_STRING_A}:
	${MAKE} ${@F} -C ${@D}

${MLX_A}:
	${MAKE} -C ${@D}

-include coffee.mk
-include norm.mk

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*
	${MAKE} $@ -C ${FT_IO_DIR}
	${MAKE} $@ -C ${FT_STRING_DIR}
	${MAKE} clean -C ${MLX_DIR}

re: clean all

fre: fclean all

.PHONY:	all clean fclean re fre

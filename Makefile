# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 14:04:02 by jodufour          #+#    #+#              #
#    Updated: 2021/08/31 04:51:05 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#             EXECUTABLE             #
######################################
NAME				=	so_long

######################################
#              COMMANDS              #
######################################
CC					=	clang -c -o
LINK				=	clang -o
RM					=	rm -rf
MKDIR				=	mkdir -p

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR				=	srcs/
OBJ_DIR				=	objs/
PRV_DIR				=	private/
PBL_DIR				=	public/

FT_IO_DIR			=	libft_io/
FT_IO_INC_DIR		=	includes/
FT_IO_INC_DIR		:=	${addprefix ${FT_IO_DIR}, ${FT_IO_INC_DIR}}

FT_MEM_DIR			=	libft_mem/
FT_MEM_INC_DIR		=	includes/
FT_MEM_INC_DIR		:=	${addprefix ${FT_MEM_DIR}, ${FT_MEM_INC_DIR}}

FT_STRING_DIR		=	libft_string/
FT_STRING_INC_DIR	=	includes/
FT_STRING_INC_DIR	:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_INC_DIR}}

MLX_DIR				=	mlx_linux/
MLX_INC_DIR			=	.
MLX_INC_DIR			:=	${addprefix ${MLX_DIR}, ${MLX_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
FT_IO_A				=	libft_io.a
FT_IO_A				:=	${addprefix ${FT_IO_DIR}, ${FT_IO_A}}

FT_MEM_A			=	libft_mem.a
FT_MEM_A			:=	${addprefix ${FT_MEM_DIR}, ${FT_MEM_A}}

FT_STRING_A			=	libft_string.a
FT_STRING_A			:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_A}}

MLX_A				=	libmlx.a
MLX_A				:=	${addprefix ${MLX_DIR}, ${MLX_A}}

######################################
#            SOURCE FILES            #
######################################
SRC					=	\
						${addprefix block/,				\
							sl_block_check_same_dim.c	\
							sl_block_check_square.c		\
							sl_block_check.c			\
							sl_block_clear.c			\
							sl_block_draw_collect.c		\
							sl_block_draw_exit.c		\
							sl_block_draw_floor.c		\
							sl_block_draw_player.c		\
							sl_block_draw_wall.c		\
							sl_block_draw.c				\
							sl_block_load_collect.c		\
							sl_block_load_exit.c		\
							sl_block_load_floor.c		\
							sl_block_load_player.c		\
							sl_block_load_wall.c		\
							sl_block_load.c				\
							sl_block.c					\
						}								\
						${addprefix event/,				\
							sl_event_move_down.c		\
							sl_event_move_left.c		\
							sl_event_move_right.c		\
							sl_event_move_up.c			\
							sl_event_none.c				\
							sl_event_quit.c				\
						}								\
						${addprefix game/,				\
							sl_game_clear.c				\
							sl_game_init.c				\
							sl_game_over.c				\
							sl_game_run.c				\
						}								\
						${addprefix hook/,				\
							sl_hook_key.c				\
							sl_hook_set.c				\
						}								\
						${addprefix map/,				\
							sl_map_check_borders.c		\
							sl_map_check_chars.c		\
							sl_map_check_width.c		\
							sl_map_check.c				\
							sl_map_clear.c				\
							sl_map_draw.c				\
							sl_map_load.c				\
							sl_map_print.c				\
							sl_map_read.c				\
							sl_map_redraw.c				\
							sl_map_update.c				\
							sl_map.c					\
						}								\
						${addprefix xptr/,				\
							sl_xptr_clear.c				\
							sl_xptr_init.c				\
							sl_xptr.c					\
						}								\
						main.c							\
						sl_err_msg.c					\
						sl_step.c

######################################
#            OBJECT FILES            #
######################################
OBJ					=	${SRC:.c=.o}
OBJ					:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP					=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS				=	-Wall -Wextra #-Werror
CFLAGS				+=	-MMD -MP
CFLAGS				+=	-I${PRV_DIR} -I${PBL_DIR}
CFLAGS				+=	-I${FT_IO_INC_DIR}
CFLAGS				+=	-I${FT_MEM_INC_DIR}
CFLAGS				+=	-I${FT_STRING_INC_DIR}
CFLAGS				+=	-I${MLX_INC_DIR}

LDFLAGS				=	-L${FT_IO_DIR} -lft_io
LDFLAGS				+=	-L${FT_MEM_DIR} -lft_mem
LDFLAGS				+=	-L${FT_STRING_DIR} -lft_string
LDFLAGS				+=	-L${MLX_DIR} -lmlx -lX11 -lXext

ifeq (${DEBUG}, true)
	CFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}:	${OBJ} ${FT_IO_A} ${FT_MEM_A} ${FT_STRING_A} ${MLX_A}
	${LINK} $@ ${OBJ} ${LDFLAGS}

all:	${NAME}

-include ${DEP}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

${FT_IO_A}:
	${MAKE} ${@F} -C ${@D}

${FT_MEM_A}:
	${MAKE} ${@F} -C ${@D}

${FT_STRING_A}:
	${MAKE} ${@F} -C ${@D}

${MLX_A}:
	${MAKE} -C ${@D}

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME}
	${MAKE} $@ -C ${FT_IO_DIR}
	${MAKE} $@ -C ${FT_STRING_DIR}

re:	fclean all

coffee:
	@echo '                                              '
	@echo '                   "   "                      '
	@echo '                  " " " "                     '
	@echo '                 " " " "                      '
	@echo '         _.-==="-"""""-"===-._                '
	@echo '        |=___   "~"~"~"   ___=|=,.            '
	@echo '        |    """======="""    |  \\           '
	@echo '        |                     |   ||          '
	@echo '        |                     |   ||          '
	@echo '        |                     |   ||          '
	@echo '        |                     |   ||          '
	@echo '        |                     |  //           '
	@echo '         \                   /=="`            '
	@echo '          \                 /                 '
	@echo '           `"--._______.--"`                  '
	@echo '                                              '

norm:
	@norminette ${SRC_DIR} ${INC_DIR} ${PRV_DIR} | grep 'Error' ; true
	@${MAKE} $@ -C ${FT_IO_DIR}
	@${MAKE} $@ -C ${FT_MEM_DIR}
	@${MAKE} $@ -C ${FT_STRING_DIR}

.PHONY:	all clean fclean re coffee norm

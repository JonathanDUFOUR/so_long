# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 14:04:02 by jodufour          #+#    #+#              #
#    Updated: 2021/12/30 21:40:56 by jodufour         ###   ########.fr        #
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
PBL_DIR				=	public/

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
						${addprefix block/,						\
							${addprefix clear/,					\
								sl_block_clear_collect.c		\
								sl_block_clear_enemy.c			\
								sl_block_clear_exit.c			\
								sl_block_clear_floor.c			\
								sl_block_clear_player.c			\
								sl_block_clear_wall.c			\
								sl_block_clear.c				\
							}									\
							${addprefix draw/,					\
								sl_block_draw_collect.c			\
								sl_block_draw_enemy_down.c		\
								sl_block_draw_enemy_left.c		\
								sl_block_draw_enemy_right.c		\
								sl_block_draw_enemy_up.c		\
								sl_block_draw_exit.c			\
								sl_block_draw_floor.c			\
								sl_block_draw_player_down.c		\
								sl_block_draw_player_left.c		\
								sl_block_draw_player_right.c	\
								sl_block_draw_player_up.c		\
								sl_block_draw_player.c			\
								sl_block_draw_wall.c			\
								sl_block_draw.c					\
							}									\
							${addprefix load/,					\
								sl_block_load_collect.c			\
								sl_block_load_enemy_down.c		\
								sl_block_load_enemy_left.c		\
								sl_block_load_enemy_right.c		\
								sl_block_load_enemy_up.c		\
								sl_block_load_enemy.c			\
								sl_block_load_exit.c			\
								sl_block_load_floor.c			\
								sl_block_load_player_down.c		\
								sl_block_load_player_left.c		\
								sl_block_load_player_right.c	\
								sl_block_load_player_up.c		\
								sl_block_load_player.c			\
								sl_block_load_wall.c			\
								sl_block_load.c					\
							}									\
							${addprefix redraw/,				\
								sl_block_redraw_enemy_down.c	\
								sl_block_redraw_enemy_left.c	\
								sl_block_redraw_enemy_right.c	\
								sl_block_redraw_enemy_up.c		\
								sl_block_redraw_enemy.c			\
							}									\
							sl_block_check_same_dim.c			\
							sl_block_check_square.c				\
							sl_block_check.c					\
							sl_block.c							\
						}										\
						${addprefix event/,						\
							sl_event_move_down.c				\
							sl_event_move_left.c				\
							sl_event_move_right.c				\
							sl_event_move_up.c					\
							sl_event_none.c						\
							sl_event_quit.c						\
						}										\
						${addprefix game/,						\
							sl_game_clear.c						\
							sl_game_init.c						\
							sl_game_over.c						\
							sl_game_run.c						\
						}										\
						${addprefix hook/,						\
							sl_hook_key.c						\
							sl_hook_set.c						\
						}										\
						${addprefix map/,						\
							${addprefix check/,					\
								sl_map_check_borders.c			\
								sl_map_check_chars.c			\
								sl_map_check_width.c			\
								sl_map_check.c					\
							}									\
							${addprefix update/,				\
								sl_map_update_enemy_down.c		\
								sl_map_update_enemy_go_down.c	\
								sl_map_update_enemy_go_left.c	\
								sl_map_update_enemy_go_right.c	\
								sl_map_update_enemy_go_up.c		\
								sl_map_update_enemy_left.c		\
								sl_map_update_enemy_right.c		\
								sl_map_update_enemy_up.c		\
								sl_map_update_enemy.c			\
								sl_map_update.c					\
							}									\
							sl_map_clear.c						\
							sl_map_draw.c						\
							sl_map_load.c						\
							sl_map_print.c						\
							sl_map_read.c						\
							sl_map_redraw.c						\
							sl_map.c							\
						}										\
						${addprefix step/,						\
							sl_step_draw_count.c				\
							sl_step_draw_title.c				\
							sl_step_update.c					\
							sl_step.c							\
						}										\
						${addprefix xptr/,						\
							sl_xptr_clear.c						\
							sl_xptr_init.c						\
							sl_xptr.c							\
						}										\
						main.c									\
						sl_err_msg.c							\
						sl_file_check_ext.c						\
						sl_is_enemy.c							\
						sl_sleep.c

######################################
#            OBJECT FILES            #
######################################
OBJ					=	${SRC:.c=.o}
OBJ					:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP					=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS				=	-Wall -Wextra -Werror
CFLAGS				+=	-MMD -MP
CFLAGS				+=	-I${PRV_DIR} -I${PBL_DIR}
CFLAGS				+=	-I${FT_IO_INC_DIR}
CFLAGS				+=	-I${FT_STRING_INC_DIR}
CFLAGS				+=	-I${MLX_INC_DIR}

LDFLAGS				=	-L${FT_IO_DIR} -lft_io
LDFLAGS				+=	-L${FT_STRING_DIR} -lft_string
LDFLAGS				+=	-L${MLX_DIR} -lmlx -lX11 -lXext

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

-include /home/jodufour/Templates/mk_files/coffee.mk
-include /home/jodufour/Templates/mk_files/norm.mk

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*
	${MAKE} $@ -C ${FT_IO_DIR}
	${MAKE} $@ -C ${FT_STRING_DIR}

re: clean all

fre: fclean all

.PHONY:	all clean fclean re fre

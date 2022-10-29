# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 14:04:02 by jodufour          #+#    #+#              #
#    Updated: 2022/10/29 07:30:02 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC					=	clang
LINK				=	clang
RM					=	rm -rf
MKDIR				=	mkdir -p

######################################
#             EXECUTABLE             #
######################################
NAME				=	so_long.out

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR				=	srcs
OBJ_DIR				=	objs
PRV_DIR				=	private

FT_IO_DIR			=	libft_io
FT_IO_INC_DIR		=	include
FT_IO_INC_DIR		:=	${addprefix ${FT_IO_DIR}/, ${FT_IO_INC_DIR}}

FT_STRING_DIR		=	libft_string
FT_STRING_INC_DIR	=	include
FT_STRING_INC_DIR	:=	${addprefix ${FT_STRING_DIR}/, ${FT_STRING_INC_DIR}}

MLX_DIR				=	mlx_linux
MLX_INC_DIR			=	.
MLX_INC_DIR			:=	${addprefix ${MLX_DIR}/, ${MLX_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
FT_IO_A				=	libft_io.a
FT_IO_A				:=	${addprefix ${FT_IO_DIR}/, ${FT_IO_A}}

FT_STRING_A			=	libft_string.a
FT_STRING_A			:=	${addprefix ${FT_STRING_DIR}/, ${FT_STRING_A}}

MLX_A				=	libmlx.a
MLX_A				:=	${addprefix ${MLX_DIR}/, ${MLX_A}}

######################################
#            SOURCE FILES            #
######################################
SRC					=	\
						${addprefix anim/,						\
							${addprefix lst/,					\
								anim_lst_add_back.c				\
								anim_lst_clear.c				\
								anim_lst_push_back.c			\
							}									\
							anim_del_one.c						\
							anim_new.c							\
						}										\
						${addprefix config/,					\
							config_clear.c						\
							config_load_enemy.c					\
							config_load_collect.c				\
							config_load_exit.c					\
							config_load_floor.c					\
							config_load_player.c				\
							config_load_wall.c					\
							config_load.c						\
						}										\
						${addprefix enemy/,						\
							${addprefix lst/,					\
								enemy_lst_add_back.c			\
								enemy_lst_clear.c				\
								enemy_lst_push_back.c			\
							}									\
							enemy_del_one.c						\
							enemy_new.c							\
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
							game_enemy_move_east.c				\
							game_enemy_move_north.c				\
							game_enemy_move_south.c				\
							game_enemy_move_west.c				\
							game_init.c							\
							game_player_interact_tile.c			\
							game_player_move_east_north.c		\
							game_player_move_east.c				\
							game_player_move_north_west.c		\
							game_player_move_north.c			\
							game_player_move_south_east.c		\
							game_player_move_south.c			\
							game_player_move_west_south.c		\
							game_player_move_west.c				\
							game_pplane_fill_background.c		\
							game_pplane_fill_enemy.c			\
							game_pplane_fill_player.c			\
							game_pplane_init.c					\
						}										\
						${addprefix hook/,						\
							hook_init.c							\
							hook_key_press.c					\
							hook_key_release.c					\
						}										\
						${addprefix img/,						\
							img_fill_img.c						\
						}										\
						${addprefix map/,						\
							map_clear.c							\
							map_load.c							\
							map_maxi_init.c						\
						}										\
						${addprefix player/,					\
							player_clear.c						\
						}										\
						${addprefix xptr/,						\
							xptr_clear.c						\
							xptr_init.c							\
						}										\
						arg_check.c								\
						err_msg.c								\
						game_over.c								\
						main.c									\
						render.c

######################################
#            OBJECT FILES            #
######################################
OBJ					=	${SRC:.c=.o}
OBJ					:=	${addprefix ${OBJ_DIR}/, ${OBJ}}

DEP					=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS				=	-c
CFLAGS				+=	-Wall -Wextra -Werror
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
	CFLAGS	+=	-DDEBUG
endif

#######################################
#                RULES                #
#######################################
.PHONY: all clean fclean re fre

${NAME}: ${OBJ} ${FT_IO_A} ${FT_STRING_A} ${MLX_A}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKDIR} ${@D}
	${CC} $< ${CFLAGS} ${OUTPUT_OPTION}

${FT_IO_A} ${FT_STRING_A}:
	${MAKE} ${@F} -C ${@D}

${MLX_A}:
	${MAKE} -C ${@D}

clean:
	${RM} ${OBJ_DIR} ${NAME} vg*core.* *.log

fclean:
	${RM} ${OBJ_DIR} ${NAME} vg*core.*
	${MAKE} $@ -C ${FT_IO_DIR}
	${MAKE} $@ -C ${FT_STRING_DIR}
	${MAKE} clean -C ${MLX_DIR}

re: clean all

fre: fclean all

-include ${HOME}/Templates/mk_files/coffee.mk
-include ${HOME}/Templates/mk_files/norm.mk

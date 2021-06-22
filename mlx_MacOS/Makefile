# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 07:41:54 by jodufour          #+#    #+#              #
#    Updated: 2021/06/22 07:42:36 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libmlx.a

CC		=	gcc -c -o
LINKER	=	ar rcs
MAKEDIR	=	mkdir -p
RM		=	rm -rf

INCLUDE	=	includes/
SRCD	=	srcs/
OBJD	=	objs/

SRCS	=	\
			mlx_xpm.c					\
			mlx_png.c					\
			mlx_mouse.m					\
			mlx_shaders.c				\
			mlx_init_loop.m				\
			mlx_new_image.m				\
			mlx_new_window.m			\
			mlx_int_str_to_wordtab.c

OBJ1	=	${SRCS:.c=.o}
OBJS	=	${OBJ1:.m=.o}
OBJS	:=	${addprefix ${OBJD}, ${OBJS}}
CFLAGS	+=	-O2 -I${INCLUDE}

# add to match string put with X11 in size and position
CFLAGS	+=	-DSTRINGPUTX11

${NAME}:	${OBJS}
	${LINKER} $@ ${OBJS}

all: ${NAME}

${OBJD}%.o:	${SRCD}%.c
	${MAKEDIR} ${OBJD}
	${CC} $@ ${CFLAGS} $<

${OBJD}%.o:	${SRCD}%.m
	${MAKEDIR} ${OBJD}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${NAME} mlx_app

re: fclean all

.PHONY:	all clean fclean re

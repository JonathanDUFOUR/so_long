# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    norm.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 02:59:16 by jodufour          #+#    #+#              #
#    Updated: 2022/04/12 04:52:44 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

norm:
	@norminette ${SRC_DIR} ${PRV_DIR} ${PBL_DIR} ${FT_IO_DIR} ${FT_STRING_DIR} | grep 'Error' ; true

normini:
	@norminette ${SRC_DIR} ${PRV_DIR} ${PBL_DIR} ${FT_IO_DIR} ${FT_STRING_DIR} | grep 'Error!' ; true

.PHONY: norm normini

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_block.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:55:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 01:08:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_BLOCK_H
# define T_BLOCK_H

# include "type/t_int.h"
# include "type/t_img.h"

typedef struct s_block	t_block;

struct s_block
{
	t_img	collect;
	t_img	exit;
	t_img	floor;
	t_img	player;
	t_img	wall;
};

int		sl_block_check_same_dim(void);
int		sl_block_check_square(void);
int		sl_block_check(void);
int		sl_block_draw(t_uint idx, char const c);
int		sl_block_load_collect(void);
int		sl_block_load_exit(void);
int		sl_block_load_floor(void);
int		sl_block_load_player(void);
int		sl_block_load_wall(void);
int		sl_block_load(void);

void	sl_block_clear(void);

t_block	*sl_block(void);

#endif

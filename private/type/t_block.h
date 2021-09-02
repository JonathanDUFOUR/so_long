/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_block.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 05:55:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 07:21:55 by jodufour         ###   ########.fr       */
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
	t_img	enemy_down;
	t_img	enemy_left;
	t_img	enemy_right;
	t_img	enemy_up;
	t_img	exit;
	t_img	floor;
	t_img	player_down;
	t_img	player_left;
	t_img	player_right;
	t_img	player_up;
	t_img	wall;
};

int		sl_block_check_same_dim(void);
int		sl_block_check_square(void);
int		sl_block_check(void);
int		sl_block_draw(t_uint idx, char const c);
int		sl_block_load_collect(void);
int		sl_block_load_enemy_down(void);
int		sl_block_load_enemy_left(void);
int		sl_block_load_enemy_right(void);
int		sl_block_load_enemy_up(void);
int		sl_block_load_enemy(void);
int		sl_block_load_exit(void);
int		sl_block_load_floor(void);
int		sl_block_load_player_down(void);
int		sl_block_load_player_left(void);
int		sl_block_load_player_right(void);
int		sl_block_load_player_up(void);
int		sl_block_load_player(void);
int		sl_block_load_wall(void);
int		sl_block_load(void);

void	sl_block_clear_collect(void);
void	sl_block_clear_enemy(void);
void	sl_block_clear_exit(void);
void	sl_block_clear_floor(void);
void	sl_block_clear_player(void);
void	sl_block_clear_wall(void);
void	sl_block_clear(void);

t_block	*sl_block(void);

#endif

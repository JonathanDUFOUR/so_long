/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:50:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 06:28:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include "type/t_int.h"

int		sl_err_msg(int err);
int		sl_event_none(void *null);
int		sl_file_check_ext(char const *file);
int		sl_game_init(char const *file);
int		sl_game_run(void);
int		sl_hook_key(int keysym, void *null);
int		sl_hook_set(void);
int		sl_step_draw_count(int color);
int		sl_step_draw_title(void);
int		sl_step_update(void);

void	sl_game_clear(void);
void	sl_game_over(char const *s);

bool	sl_is_enemy(char const c);

t_uint	*sl_step(void);
t_uint	*sl_sleep(void);

#endif

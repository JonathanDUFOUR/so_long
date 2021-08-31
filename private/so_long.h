/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:50:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/31 04:07:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "type/t_int.h"

int		sl_err_msg(int err);
int		sl_game_init(char const *ber);
int		sl_game_run(void);
int		sl_hook_key(int keysym, void *null);
int		sl_hook_set(void);
int		sl_event_none(void *null);

void	sl_game_clear(void);
void	sl_game_over(char const *s);

t_uint	*sl_step(void);

#endif
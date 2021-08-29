/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:50:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/30 00:40:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

int		sl_err_msg(int err);
int		sl_game_init(char const *ber);
int		sl_game_run(void);
int		sl_hook_key(int keysym, void *null);
int		sl_hook_set(void);
int		sl_event_none(void *null);

void	sl_game_clear(void);

#endif

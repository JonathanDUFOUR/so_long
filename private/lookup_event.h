/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_event.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 00:42:21 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/23 20:15:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_EVENT_H
# define LOOKUP_EVENT_H

# include <X11/keysym.h>
# include "t_all.h"
# include <stddef.h>

typedef struct s_event	t_event;
typedef void			(*t_fct)(t_all *const a);

struct s_event
{
	int const	keysym;
	t_fct const	press;
	t_fct const	release;
};

void	event_move_east_turn_on(t_all *const a)
		__attribute__((nonnull));
void	event_move_east_turn_off(t_all *const a)
		__attribute__((nonnull));
void	event_move_north_turn_on(t_all *const a)
		__attribute__((nonnull));
void	event_move_north_turn_off(t_all *const a)
		__attribute__((nonnull));
void	event_move_west_turn_on(t_all *const a)
		__attribute__((nonnull));
void	event_move_west_turn_off(t_all *const a)
		__attribute__((nonnull));
void	event_move_south_turn_on(t_all *const a)
		__attribute__((nonnull));
void	event_move_south_turn_off(t_all *const a)
		__attribute__((nonnull));
void	event_quit(t_all *const a)
		__attribute__((nonnull));

static t_event const	g_event[] = {
{XK_d, event_move_east_turn_on, event_move_east_turn_off},
{XK_w, event_move_north_turn_on, event_move_north_turn_off},
{XK_a, event_move_west_turn_on, event_move_west_turn_off},
{XK_s, event_move_south_turn_on, event_move_south_turn_off},
{XK_Escape, event_quit, NULL},
{0}
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_event.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 00:42:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 21:34:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_EVENT_H
# define LOOKUP_EVENT_H

# include <stddef.h>
# include <X11/keysym.h>

typedef struct s_event	t_event;

struct s_event
{
	int	keysym;
	int	(*f)(void);
};

int	sl_event_move_down(void);
int	sl_event_move_left(void);
int	sl_event_move_right(void);
int	sl_event_move_up(void);
int	sl_event_quit(void);

static t_event const	g_event[] = {
{XK_Escape, sl_event_quit},
{XK_s, sl_event_move_down},
{XK_a, sl_event_move_left},
{XK_d, sl_event_move_right},
{XK_w, sl_event_move_up},
{XK_Down, sl_event_move_down},
{XK_Left, sl_event_move_left},
{XK_Right, sl_event_move_right},
{XK_Up, sl_event_move_up},
{0, NULL}
};

#endif

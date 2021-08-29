/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_lookup.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 00:42:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/30 00:53:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_LOOKUP_H
# define EVENT_LOOKUP_H

# include <stddef.h>
# include <X11/keysym.h>

typedef struct s_event	t_event;

struct s_event
{
	int	keysym;
	int	(*f)(void);
};

int	sl_event_quit(void);

static t_event const	g_event[] = {
	{XK_Escape, sl_event_quit},
	{0, NULL}
};

#endif

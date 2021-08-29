/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 00:00:39 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/30 00:50:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_lookup.h"
#include "enum/e_ret.h"

/*
**	set running events from key hooks
*/
int	sl_hook_key(int keysym, void *null)
{
	int	i;

	(void)null;
	i = 0;
	while (g_event[i].f && keysym != g_event[i].keysym)
		++i;
	if (g_event[i].f)
		return (g_event[i].f());
	return (NO_HOOK_ERR);
}

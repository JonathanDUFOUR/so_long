/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:18:35 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/13 14:45:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lookup_event.h"
#include "e_ret.h"

/**
	@brief	Trigger the event corresponding to the pressed key.

	@param	keysym The pressed key.
	@param	a The all structure to send to the corresponding event.

	@return	The updated program status, always SUCCESS.
*/
int	hook_key_press(int const keysym, t_all *const a)
{
	t_uint	idx;

	idx = 0U;
	while (g_event[idx].keysym && g_event[idx].keysym != keysym)
		++idx;
	if (g_event[idx].press)
		g_event[idx].press(a);
	return (a->ret = SUCCESS);
}

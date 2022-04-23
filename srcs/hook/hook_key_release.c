/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_release.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:33:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/13 14:45:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lookup_event.h"
#include "e_ret.h"

/**
	@brief	Trigger the event corresponding to the released key.

	@param	keysym The released key.
	@param	a The all structure send to the corresponding event.

	@return	The updated program status, always SUCCESS.
*/
int	hook_key_release(int const keysym, t_all *const a)
{
	t_uint	idx;

	idx = 0U;
	while (g_event[idx].keysym && g_event[idx].keysym != keysym)
		++idx;
	if (g_event[idx].release)
		g_event[idx].release(a);
	return (a->ret = SUCCESS);
}

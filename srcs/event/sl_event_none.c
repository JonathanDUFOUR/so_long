/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_event_none.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 23:58:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/30 00:56:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enum/e_ret.h"

/*
**	default behavior when no hooks are triggered
*/
int	sl_event_none(void *null)
{
	(void)null;
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:13:19 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 10:23:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_config.h"
#include "e_ret.h"

/**
	@brief	Load images defined in settings.h
			and store them in the given configuration structure.

	@param	c The configuration structure to fill.
	@param	x The xptr structure to use for image creation.
	@param	ret The program status reference.

	@return	The updated program status.
*/
int	config_load(t_config *const c, t_xptr const *const x, int *const ret)
{
	if (config_load_enemy(c, x, ret)
		|| config_load_exit(c, x, ret)
		|| config_load_floor(c, x, ret)
		|| config_load_player(c, x, ret)
		|| config_load_wall(c, x, ret))
		return (*ret);
	return (*ret = SUCCESS);
}

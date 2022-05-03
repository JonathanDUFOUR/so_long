/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_del_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:43:36 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 15:49:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_enemy.h"

/**
	@brief	Release all resources contained in the given enemy structure.

	@param e The enemy structure to delete.
*/
void	enemy_del_one(t_enemy *const e)
{
	ft_bzero(e, sizeof(t_enemy));
}

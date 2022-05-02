/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:59:13 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 00:30:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_player.h"

/**
	@brief	Free the allocated memory in the given player structure.
	
	@param	p The player structure containing the memory to free.
*/
void	player_clear(t_player *const p)
{
	ft_bzero(p, sizeof(t_player));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:52:39 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/23 16:03:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "t_all.h"
#include "e_ret.h"

/**
	@brief	End the mlx loop to end the program.

	@param	a The all structure containing the game and display data.
*/
void	event_quit(t_all *const a)
{
	mlx_loop_end(a->x.mlx);
}

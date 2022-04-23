/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:07:27 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/13 14:47:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_all.h"
#include "e_ret.h"

/**
	@brief	Display the current game image on the window.

	@param	a The all structure containing the game and display data.

	@return	The updated program status, always SUCCESS.
*/
int	render(t_all *const a)
{
	return (a->ret = SUCCESS);
}

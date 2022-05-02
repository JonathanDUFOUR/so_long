/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:59:56 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 23:00:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "mlx.h"
#include "t_xptr.h"

/**
	@brief	Write an end message on stdout, and end the mlx loop.

	@param	msg The message to write.
	@param	distance The distance the player has reached.
	@param	x The xptr structure containing the display and window pointers.
*/
void	game_over(
	char const *const msg,
	double const distance,
	t_xptr const *const x)
{
	ft_putendl_fd(msg, STDOUT_FILENO);
	ft_putstr_fd("Distance: ", STDOUT_FILENO);
	ft_putdouble_fd(distance, 2U, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	mlx_loop_end(x->mlx);
}

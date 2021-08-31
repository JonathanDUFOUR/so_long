/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:04:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/30 23:16:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "ft_string.h"
#include "type/t_xptr.h"

/*
**	print a custom game over message in terminal
**	end the mlx_loop
*/
void	sl_game_over(char const *s)
{
	t_xptr *const	xptr = sl_xptr();

	write(1, s, ft_strlen(s));
	mlx_loop_end(xptr->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:40:57 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 02:04:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "mlx.h"
#include "t_all.h"
#include "e_ret.h"

/**
	@brief	Display the current score of the player on the window.

	@param	a The all structure containing the game and display data.

	@return	The updated program status.
*/
int	render_score(t_all *const a)
{
	char const	*str = ft_dtoa(a->g.p.distance, 2U);

	if (!str)
		return (a->ret = MALLOC_ERR);
	mlx_put_image_to_window(a->x.mlx, a->x.win, a->c.sidebar.ptr, 0, 0);
	mlx_string_put(a->x.mlx, a->x.win, 21, 15, 0x00ffffff, "Distance: ");
	mlx_string_put(a->x.mlx, a->x.win, 84, 15, 0x00ffffff, (char *)str);
	free((void *)str);
	return (a->ret = SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:07:27 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/06 23:56:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "mlx.h"
#include "t_all.h"
#include "e_axis.h"
#include "e_ret.h"

inline static int	__score(t_all *const a)
{
	static double	old = 0.0;
	char const		*str = ft_dtoa(old, 2U);

	if (!str)
		return (a->ret = MALLOC_ERR);
	mlx_string_put(a->x.mlx, a->x.win, 84, 15, 0x00000000, (char *)str);
	free((void *)str);
	str = ft_dtoa(a->g.p.distance, 2U);
	if (!str)
		return (a->ret = MALLOC_ERR);
	mlx_string_put(a->x.mlx, a->x.win, 84, 15, 0x00ffffff, (char *)str);
	free((void *)str);
	old = a->g.p.distance;
	return (a->ret = SUCCESS);
}

/**
	@brief	Display the current game image on the window.

	@param	a The all structure containing the game and display data.

	@return	The updated program status.
*/
int	render(t_all *const a)
{
	game_pplane_fill_background(&a->g);
	game_pplane_fill_player(&a->g);
	game_pplane_fill_enemy(&a->g);
	if (__score(a))
		return (a->ret);
	mlx_put_image_to_window(
		a->x.mlx,
		a->x.win,
		a->g.pplane.ptr,
		0, SIDEBAR_H);
	return (a->ret = SUCCESS);
}

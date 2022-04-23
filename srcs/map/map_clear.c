/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 05:56:52 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 08:41:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "ft_string.h"
#include "t_map.h"

/**
	@brief	Free the allocated memory in the given map structure.
	
	@param	m The map structure containing the memory to free.
	@param	x The xptr structure containing the display and window pointers.
*/
void	map_clear(t_map *const m, t_xptr const *const x)
{
	free(m->ptr);
	if (m->maxi.ptr)
		mlx_destroy_image(x->mlx, m->maxi.ptr);
	if (m->mini.ptr)
		mlx_destroy_image(x->mlx, m->mini.ptr);
	ft_bzero(m, sizeof(t_map));
}

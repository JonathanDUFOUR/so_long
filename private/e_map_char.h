/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_map_char.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 04:02:48 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/03 00:06:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_MAP_CHAR_H
# define E_MAP_CHAR_H

enum	e_map_char
{
	WALL,
	FLOOR,
	COLLECT,
	EXIT,
	PLAYER,
	ENEMY_EAST,
	ENEMY_NORTH,
	ENEMY_WEST,
	ENEMY_SOUTH
};

#endif

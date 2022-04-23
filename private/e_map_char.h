/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_map_char.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 04:02:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/02 04:58:35 by jodufour         ###   ########.fr       */
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
	ENEMY_DOWN,
	ENEMY_LEFT,
	ENEMY_RIGHT,
	ENEMY_UP
};

#endif

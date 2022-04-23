/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 03:54:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 11:50:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# define MAP_CHAR "10CEPenws"
/*
**	Must be as followed:
**
**	MAP_CHAR[0]: wall
**	MAP_CHAR[1]: floor
**	MAP_CHAR[2]: collect
**	MAP_CHAR[3]: exit
**	MAP_CHAR[4]: player
**	MAP_CHAR[5]: enemy going east
**	MAP_CHAR[6]: enemy going north
**	MAP_CHAR[7]: enemy going west
**	MAP_CHAR[8]: enemy going south
*/

# define WIN_TITLE			"so_long"
# define WIN_W				800
# define WIN_H				600

# define IMG_W				32
# define IMG_H				32

static char const *const	g_xpm_enemy[] = {
	"resources/xpm/apple.xpm",
	"resources/xpm/apple.xpm",
	"resources/xpm/apple.xpm",
	"resources/xpm/apple.xpm"
};

static char const *const	g_xpm_player[] = {
	"resources/xpm/penguin_east.xpm",
	"resources/xpm/penguin_north.xpm",
	"resources/xpm/penguin_west.xpm",
	"resources/xpm/penguin_south.xpm",
	"resources/xpm/penguin_north_east.xpm",
	"resources/xpm/penguin_north_west.xpm",
	"resources/xpm/penguin_south_west.xpm",
	"resources/xpm/penguin_south_east.xpm"
};

# define XPM_COLLECT		"resources/xpm/arch.xpm"
# define XPM_EXIT			"resources/xpm/stairs.xpm"
# define XPM_FLOOR			"resources/xpm/floor.xpm"
# define XPM_WALL			"resources/xpm/wall.xpm"

# define VICTORY_MSG		">>> SUCCESS <<<"
# define DEFEAT_MSG			">>> FAILURE <<<"

#endif

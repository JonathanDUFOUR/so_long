/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 03:54:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/11 22:27:08 by jodufour         ###   ########.fr       */
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

# ifdef DEBUG
#  define SLEEP_TIME		0U
# else
#  define SLEEP_TIME		5U
# endif

# define WIN_TITLE			"so_long"
# ifdef DEBUG
#  define WIN_W				400
#  define WIN_H				300
# else
#  define WIN_W				800
#  define WIN_H				600
# endif

# define SIDEBAR_H			21

# define IMG_W				32
# define IMG_H				32

# ifdef DEBUG
#  define PLAYER_SPEED		3.0
#  define ENEMY_SPEED		1.5
# else
#  define PLAYER_SPEED		1.0
#  define ENEMY_SPEED		0.5
# endif

# define HITBOX				15

static char const *const	g_xpm_enemy[][] = {
{
	"resources/xpm/blinky_east_00.xpm",
	"resources/xpm/blinky_east_00.xpm",
	"resources/xpm/blinky_east_00.xpm",
	"resources/xpm/blinky_east_01.xpm",
	"resources/xpm/blinky_east_01.xpm",
	"resources/xpm/blinky_east_01.xpm",
	"resources/xpm/blinky_east_00.xpm",
	"resources/xpm/blinky_east_00.xpm",
	"resources/xpm/blinky_east_00.xpm",
	"resources/xpm/blinky_east_01.xpm",
	"resources/xpm/blinky_east_01.xpm",
	"resources/xpm/blinky_east_01.xpm",
	"resources/xpm/blinky_east_00.xpm",
	"resources/xpm/blinky_east_00.xpm",
	"resources/xpm/blinky_east_00.xpm",
	"resources/xpm/blinky_east_01.xpm",
	"resources/xpm/blinky_east_01.xpm",
	"resources/xpm/blinky_east_01.xpm",
	0
},
{
	"resources/xpm/clyde_north_00.xpm",
	"resources/xpm/clyde_north_00.xpm",
	"resources/xpm/clyde_north_00.xpm",
	"resources/xpm/clyde_north_01.xpm",
	"resources/xpm/clyde_north_01.xpm",
	"resources/xpm/clyde_north_01.xpm",
	"resources/xpm/clyde_north_00.xpm",
	"resources/xpm/clyde_north_00.xpm",
	"resources/xpm/clyde_north_00.xpm",
	"resources/xpm/clyde_north_01.xpm",
	"resources/xpm/clyde_north_01.xpm",
	"resources/xpm/clyde_north_01.xpm",
	"resources/xpm/clyde_north_00.xpm",
	"resources/xpm/clyde_north_00.xpm",
	"resources/xpm/clyde_north_00.xpm",
	"resources/xpm/clyde_north_01.xpm",
	"resources/xpm/clyde_north_01.xpm",
	"resources/xpm/clyde_north_01.xpm",
	0
},
{
	"resources/xpm/inky_west_00.xpm",
	"resources/xpm/inky_west_00.xpm",
	"resources/xpm/inky_west_00.xpm",
	"resources/xpm/inky_west_01.xpm",
	"resources/xpm/inky_west_01.xpm",
	"resources/xpm/inky_west_01.xpm",
	"resources/xpm/inky_west_00.xpm",
	"resources/xpm/inky_west_00.xpm",
	"resources/xpm/inky_west_00.xpm",
	"resources/xpm/inky_west_01.xpm",
	"resources/xpm/inky_west_01.xpm",
	"resources/xpm/inky_west_01.xpm",
	"resources/xpm/inky_west_00.xpm",
	"resources/xpm/inky_west_00.xpm",
	"resources/xpm/inky_west_00.xpm",
	"resources/xpm/inky_west_01.xpm",
	"resources/xpm/inky_west_01.xpm",
	"resources/xpm/inky_west_01.xpm",
	0
},
{
	"resources/xpm/pinky_south_00.xpm",
	"resources/xpm/pinky_south_00.xpm",
	"resources/xpm/pinky_south_00.xpm",
	"resources/xpm/pinky_south_01.xpm",
	"resources/xpm/pinky_south_01.xpm",
	"resources/xpm/pinky_south_01.xpm",
	"resources/xpm/pinky_south_00.xpm",
	"resources/xpm/pinky_south_00.xpm",
	"resources/xpm/pinky_south_00.xpm",
	"resources/xpm/pinky_south_01.xpm",
	"resources/xpm/pinky_south_01.xpm",
	"resources/xpm/pinky_south_01.xpm",
	"resources/xpm/pinky_south_00.xpm",
	"resources/xpm/pinky_south_00.xpm",
	"resources/xpm/pinky_south_00.xpm",
	"resources/xpm/pinky_south_01.xpm",
	"resources/xpm/pinky_south_01.xpm",
	"resources/xpm/pinky_south_01.xpm",
	0
}
};

static char const *const	g_xpm_player[][] = {
{
	"resources/xpm/tux_east_00.xpm",
	"resources/xpm/tux_east_01.xpm",
	"resources/xpm/tux_east_02.xpm",
	"resources/xpm/tux_east_03.xpm",
	"resources/xpm/tux_east_04.xpm",
	"resources/xpm/tux_east_05.xpm",
	"resources/xpm/tux_east_06.xpm",
	"resources/xpm/tux_east_07.xpm",
	"resources/xpm/tux_east_08.xpm",
	"resources/xpm/tux_east_09.xpm",
	"resources/xpm/tux_east_10.xpm",
	"resources/xpm/tux_east_11.xpm",
	"resources/xpm/tux_east_12.xpm",
	"resources/xpm/tux_east_13.xpm",
	"resources/xpm/tux_east_14.xpm",
	"resources/xpm/tux_east_15.xpm",
	"resources/xpm/tux_east_16.xpm",
	"resources/xpm/tux_east_17.xpm",
	0
},
{
	"resources/xpm/tux_north_00.xpm",
	"resources/xpm/tux_north_01.xpm",
	"resources/xpm/tux_north_02.xpm",
	"resources/xpm/tux_north_03.xpm",
	"resources/xpm/tux_north_04.xpm",
	"resources/xpm/tux_north_05.xpm",
	"resources/xpm/tux_north_06.xpm",
	"resources/xpm/tux_north_07.xpm",
	"resources/xpm/tux_north_08.xpm",
	"resources/xpm/tux_north_09.xpm",
	"resources/xpm/tux_north_10.xpm",
	"resources/xpm/tux_north_11.xpm",
	"resources/xpm/tux_north_12.xpm",
	"resources/xpm/tux_north_13.xpm",
	"resources/xpm/tux_north_14.xpm",
	"resources/xpm/tux_north_15.xpm",
	"resources/xpm/tux_north_16.xpm",
	"resources/xpm/tux_north_17.xpm",
	0
},
{
	"resources/xpm/tux_west_00.xpm",
	"resources/xpm/tux_west_01.xpm",
	"resources/xpm/tux_west_02.xpm",
	"resources/xpm/tux_west_03.xpm",
	"resources/xpm/tux_west_04.xpm",
	"resources/xpm/tux_west_05.xpm",
	"resources/xpm/tux_west_06.xpm",
	"resources/xpm/tux_west_07.xpm",
	"resources/xpm/tux_west_08.xpm",
	"resources/xpm/tux_west_09.xpm",
	"resources/xpm/tux_west_10.xpm",
	"resources/xpm/tux_west_11.xpm",
	"resources/xpm/tux_west_12.xpm",
	"resources/xpm/tux_west_13.xpm",
	"resources/xpm/tux_west_14.xpm",
	"resources/xpm/tux_west_15.xpm",
	"resources/xpm/tux_west_16.xpm",
	"resources/xpm/tux_west_17.xpm",
	0
},
{
	"resources/xpm/tux_south_00.xpm",
	"resources/xpm/tux_south_01.xpm",
	"resources/xpm/tux_south_02.xpm",
	"resources/xpm/tux_south_03.xpm",
	"resources/xpm/tux_south_04.xpm",
	"resources/xpm/tux_south_05.xpm",
	"resources/xpm/tux_south_06.xpm",
	"resources/xpm/tux_south_07.xpm",
	"resources/xpm/tux_south_08.xpm",
	"resources/xpm/tux_south_09.xpm",
	"resources/xpm/tux_south_10.xpm",
	"resources/xpm/tux_south_11.xpm",
	"resources/xpm/tux_south_12.xpm",
	"resources/xpm/tux_south_13.xpm",
	"resources/xpm/tux_south_14.xpm",
	"resources/xpm/tux_south_15.xpm",
	"resources/xpm/tux_south_16.xpm",
	"resources/xpm/tux_south_17.xpm",
	0
},
{
	"resources/xpm/tux_east_00.xpm",
	"resources/xpm/tux_east_01.xpm",
	"resources/xpm/tux_east_02.xpm",
	"resources/xpm/tux_east_03.xpm",
	"resources/xpm/tux_east_04.xpm",
	"resources/xpm/tux_east_05.xpm",
	"resources/xpm/tux_east_06.xpm",
	"resources/xpm/tux_east_07.xpm",
	"resources/xpm/tux_east_08.xpm",
	"resources/xpm/tux_east_09.xpm",
	"resources/xpm/tux_east_10.xpm",
	"resources/xpm/tux_east_11.xpm",
	"resources/xpm/tux_east_12.xpm",
	"resources/xpm/tux_east_13.xpm",
	"resources/xpm/tux_east_14.xpm",
	"resources/xpm/tux_east_15.xpm",
	"resources/xpm/tux_east_16.xpm",
	"resources/xpm/tux_east_17.xpm",
	0
},
{
	"resources/xpm/tux_west_00.xpm",
	"resources/xpm/tux_west_01.xpm",
	"resources/xpm/tux_west_02.xpm",
	"resources/xpm/tux_west_03.xpm",
	"resources/xpm/tux_west_04.xpm",
	"resources/xpm/tux_west_05.xpm",
	"resources/xpm/tux_west_06.xpm",
	"resources/xpm/tux_west_07.xpm",
	"resources/xpm/tux_west_08.xpm",
	"resources/xpm/tux_west_09.xpm",
	"resources/xpm/tux_west_10.xpm",
	"resources/xpm/tux_west_11.xpm",
	"resources/xpm/tux_west_12.xpm",
	"resources/xpm/tux_west_13.xpm",
	"resources/xpm/tux_west_14.xpm",
	"resources/xpm/tux_west_15.xpm",
	"resources/xpm/tux_west_16.xpm",
	"resources/xpm/tux_west_17.xpm",
	0
},
{
	"resources/xpm/tux_west_00.xpm",
	"resources/xpm/tux_west_01.xpm",
	"resources/xpm/tux_west_02.xpm",
	"resources/xpm/tux_west_03.xpm",
	"resources/xpm/tux_west_04.xpm",
	"resources/xpm/tux_west_05.xpm",
	"resources/xpm/tux_west_06.xpm",
	"resources/xpm/tux_west_07.xpm",
	"resources/xpm/tux_west_08.xpm",
	"resources/xpm/tux_west_09.xpm",
	"resources/xpm/tux_west_10.xpm",
	"resources/xpm/tux_west_11.xpm",
	"resources/xpm/tux_west_12.xpm",
	"resources/xpm/tux_west_13.xpm",
	"resources/xpm/tux_west_14.xpm",
	"resources/xpm/tux_west_15.xpm",
	"resources/xpm/tux_west_16.xpm",
	"resources/xpm/tux_west_17.xpm",
	0
},
{
	"resources/xpm/tux_east_00.xpm",
	"resources/xpm/tux_east_01.xpm",
	"resources/xpm/tux_east_02.xpm",
	"resources/xpm/tux_east_03.xpm",
	"resources/xpm/tux_east_04.xpm",
	"resources/xpm/tux_east_05.xpm",
	"resources/xpm/tux_east_06.xpm",
	"resources/xpm/tux_east_07.xpm",
	"resources/xpm/tux_east_08.xpm",
	"resources/xpm/tux_east_09.xpm",
	"resources/xpm/tux_east_10.xpm",
	"resources/xpm/tux_east_11.xpm",
	"resources/xpm/tux_east_12.xpm",
	"resources/xpm/tux_east_13.xpm",
	"resources/xpm/tux_east_14.xpm",
	"resources/xpm/tux_east_15.xpm",
	"resources/xpm/tux_east_16.xpm",
	"resources/xpm/tux_east_17.xpm",
	0
}
};

# define XPM_COLLECT		"resources/xpm/arch.xpm"
# define XPM_EXIT			"resources/xpm/stairs.xpm"
# define XPM_FLOOR			"resources/xpm/floor.xpm"
# define XPM_WALL			"resources/xpm/wall.xpm"

# define VICTORY_MSG		">>> SUCCESS <<<"
# define DEFEAT_MSG			">>> FAILURE <<<"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 03:54:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/05 23:34:58 by jodufour         ###   ########.fr       */
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

# define SLEEP_TIME			8U

# define WIN_TITLE			"so_long"
# define WIN_W				800
# define WIN_H				600

# define SIDEBAR_H			21

# define IMG_W				32
# define IMG_H				32

# define ANIMATE_CNT		18U

# define PLAYER_SPEED		1.0
# define ENEMY_SPEED		0.5

# define HITBOX				15

static char const *const	g_xpm_enemy[][ANIMATE_CNT] = {
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
	"resources/xpm/blinky_east_01.xpm"
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
	"resources/xpm/clyde_north_01.xpm"
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
	"resources/xpm/inky_west_01.xpm"
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
	"resources/xpm/pinky_south_01.xpm"
}
};

static char const *const	g_xpm_player[][ANIMATE_CNT] = {
{
	"resources/xpm/pacman_east_00.xpm",
	"resources/xpm/pacman_east_01.xpm",
	"resources/xpm/pacman_east_02.xpm",
	"resources/xpm/pacman_east_03.xpm",
	"resources/xpm/pacman_east_04.xpm",
	"resources/xpm/pacman_east_05.xpm",
	"resources/xpm/pacman_east_06.xpm",
	"resources/xpm/pacman_east_07.xpm",
	"resources/xpm/pacman_east_08.xpm",
	"resources/xpm/pacman_east_09.xpm",
	"resources/xpm/pacman_east_08.xpm",
	"resources/xpm/pacman_east_07.xpm",
	"resources/xpm/pacman_east_06.xpm",
	"resources/xpm/pacman_east_05.xpm",
	"resources/xpm/pacman_east_04.xpm",
	"resources/xpm/pacman_east_03.xpm",
	"resources/xpm/pacman_east_02.xpm",
	"resources/xpm/pacman_east_01.xpm"
},
{
	"resources/xpm/pacman_north_00.xpm",
	"resources/xpm/pacman_north_01.xpm",
	"resources/xpm/pacman_north_02.xpm",
	"resources/xpm/pacman_north_03.xpm",
	"resources/xpm/pacman_north_04.xpm",
	"resources/xpm/pacman_north_05.xpm",
	"resources/xpm/pacman_north_06.xpm",
	"resources/xpm/pacman_north_07.xpm",
	"resources/xpm/pacman_north_08.xpm",
	"resources/xpm/pacman_north_09.xpm",
	"resources/xpm/pacman_north_08.xpm",
	"resources/xpm/pacman_north_07.xpm",
	"resources/xpm/pacman_north_06.xpm",
	"resources/xpm/pacman_north_05.xpm",
	"resources/xpm/pacman_north_04.xpm",
	"resources/xpm/pacman_north_03.xpm",
	"resources/xpm/pacman_north_02.xpm",
	"resources/xpm/pacman_north_01.xpm"
},
{
	"resources/xpm/pacman_west_00.xpm",
	"resources/xpm/pacman_west_01.xpm",
	"resources/xpm/pacman_west_02.xpm",
	"resources/xpm/pacman_west_03.xpm",
	"resources/xpm/pacman_west_04.xpm",
	"resources/xpm/pacman_west_05.xpm",
	"resources/xpm/pacman_west_06.xpm",
	"resources/xpm/pacman_west_07.xpm",
	"resources/xpm/pacman_west_08.xpm",
	"resources/xpm/pacman_west_09.xpm",
	"resources/xpm/pacman_west_08.xpm",
	"resources/xpm/pacman_west_07.xpm",
	"resources/xpm/pacman_west_06.xpm",
	"resources/xpm/pacman_west_05.xpm",
	"resources/xpm/pacman_west_04.xpm",
	"resources/xpm/pacman_west_03.xpm",
	"resources/xpm/pacman_west_02.xpm",
	"resources/xpm/pacman_west_01.xpm"
},
{
	"resources/xpm/pacman_south_00.xpm",
	"resources/xpm/pacman_south_01.xpm",
	"resources/xpm/pacman_south_02.xpm",
	"resources/xpm/pacman_south_03.xpm",
	"resources/xpm/pacman_south_04.xpm",
	"resources/xpm/pacman_south_05.xpm",
	"resources/xpm/pacman_south_06.xpm",
	"resources/xpm/pacman_south_07.xpm",
	"resources/xpm/pacman_south_08.xpm",
	"resources/xpm/pacman_south_09.xpm",
	"resources/xpm/pacman_south_08.xpm",
	"resources/xpm/pacman_south_07.xpm",
	"resources/xpm/pacman_south_06.xpm",
	"resources/xpm/pacman_south_05.xpm",
	"resources/xpm/pacman_south_04.xpm",
	"resources/xpm/pacman_south_03.xpm",
	"resources/xpm/pacman_south_02.xpm",
	"resources/xpm/pacman_south_01.xpm"
},
{
	"resources/xpm/pacman_east_north_00.xpm",
	"resources/xpm/pacman_east_north_01.xpm",
	"resources/xpm/pacman_east_north_02.xpm",
	"resources/xpm/pacman_east_north_03.xpm",
	"resources/xpm/pacman_east_north_04.xpm",
	"resources/xpm/pacman_east_north_05.xpm",
	"resources/xpm/pacman_east_north_06.xpm",
	"resources/xpm/pacman_east_north_07.xpm",
	"resources/xpm/pacman_east_north_08.xpm",
	"resources/xpm/pacman_east_north_09.xpm",
	"resources/xpm/pacman_east_north_08.xpm",
	"resources/xpm/pacman_east_north_07.xpm",
	"resources/xpm/pacman_east_north_06.xpm",
	"resources/xpm/pacman_east_north_05.xpm",
	"resources/xpm/pacman_east_north_04.xpm",
	"resources/xpm/pacman_east_north_03.xpm",
	"resources/xpm/pacman_east_north_02.xpm",
	"resources/xpm/pacman_east_north_01.xpm"
},
{
	"resources/xpm/pacman_north_west_00.xpm",
	"resources/xpm/pacman_north_west_01.xpm",
	"resources/xpm/pacman_north_west_02.xpm",
	"resources/xpm/pacman_north_west_03.xpm",
	"resources/xpm/pacman_north_west_04.xpm",
	"resources/xpm/pacman_north_west_05.xpm",
	"resources/xpm/pacman_north_west_06.xpm",
	"resources/xpm/pacman_north_west_07.xpm",
	"resources/xpm/pacman_north_west_08.xpm",
	"resources/xpm/pacman_north_west_09.xpm",
	"resources/xpm/pacman_north_west_08.xpm",
	"resources/xpm/pacman_north_west_07.xpm",
	"resources/xpm/pacman_north_west_06.xpm",
	"resources/xpm/pacman_north_west_05.xpm",
	"resources/xpm/pacman_north_west_04.xpm",
	"resources/xpm/pacman_north_west_03.xpm",
	"resources/xpm/pacman_north_west_02.xpm",
	"resources/xpm/pacman_north_west_01.xpm"
},
{
	"resources/xpm/pacman_west_south_00.xpm",
	"resources/xpm/pacman_west_south_01.xpm",
	"resources/xpm/pacman_west_south_02.xpm",
	"resources/xpm/pacman_west_south_03.xpm",
	"resources/xpm/pacman_west_south_04.xpm",
	"resources/xpm/pacman_west_south_05.xpm",
	"resources/xpm/pacman_west_south_06.xpm",
	"resources/xpm/pacman_west_south_07.xpm",
	"resources/xpm/pacman_west_south_08.xpm",
	"resources/xpm/pacman_west_south_09.xpm",
	"resources/xpm/pacman_west_south_08.xpm",
	"resources/xpm/pacman_west_south_07.xpm",
	"resources/xpm/pacman_west_south_06.xpm",
	"resources/xpm/pacman_west_south_05.xpm",
	"resources/xpm/pacman_west_south_04.xpm",
	"resources/xpm/pacman_west_south_03.xpm",
	"resources/xpm/pacman_west_south_02.xpm",
	"resources/xpm/pacman_west_south_01.xpm"
},
{
	"resources/xpm/pacman_south_east_00.xpm",
	"resources/xpm/pacman_south_east_01.xpm",
	"resources/xpm/pacman_south_east_02.xpm",
	"resources/xpm/pacman_south_east_03.xpm",
	"resources/xpm/pacman_south_east_04.xpm",
	"resources/xpm/pacman_south_east_05.xpm",
	"resources/xpm/pacman_south_east_06.xpm",
	"resources/xpm/pacman_south_east_07.xpm",
	"resources/xpm/pacman_south_east_08.xpm",
	"resources/xpm/pacman_south_east_09.xpm",
	"resources/xpm/pacman_south_east_08.xpm",
	"resources/xpm/pacman_south_east_07.xpm",
	"resources/xpm/pacman_south_east_06.xpm",
	"resources/xpm/pacman_south_east_05.xpm",
	"resources/xpm/pacman_south_east_04.xpm",
	"resources/xpm/pacman_south_east_03.xpm",
	"resources/xpm/pacman_south_east_02.xpm",
	"resources/xpm/pacman_south_east_01.xpm"
}
};

# define XPM_COLLECT		"resources/xpm/cherry.xpm"
# define XPM_EXIT			"resources/xpm/stairs.xpm"
# define XPM_FLOOR			"resources/xpm/floor.xpm"
# define XPM_SIDEBAR		"resources/xpm/sidebar_800_black.xpm"
# define XPM_WALL			"resources/xpm/wall.xpm"

# define VICTORY_MSG		">>> SUCCESS <<<"
# define DEFEAT_MSG			">>> FAILURE <<<"

#endif

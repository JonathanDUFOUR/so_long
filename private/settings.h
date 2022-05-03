/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 03:54:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/04 00:12:32 by jodufour         ###   ########.fr       */
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

# define SLEEP_TIME			0U

# define WIN_TITLE			"so_long"
# define WIN_W				800
# define WIN_H				600

# define SIDEBAR_H			42

# define IMG_W				32
# define IMG_H				32

# define ANIMATE_CNT		18U

# define PLAYER_SPEED		8.0

# define HITBOX			15

static char const *const	g_xpm_enemy[][ANIMATE_CNT] = {
{
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm",
	"resources/xpm/spike_east.xpm"
},
{
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm",
	"resources/xpm/spike_north.xpm"
},
{
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm",
	"resources/xpm/spike_west.xpm"
},
{
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm",
	"resources/xpm/spike_south.xpm"
}
};

static char const *const	g_xpm_player[][ANIMATE_CNT] = {
{
	"resources/xpm/going_east_00.xpm",
	"resources/xpm/going_east_01.xpm",
	"resources/xpm/going_east_02.xpm",
	"resources/xpm/going_east_03.xpm",
	"resources/xpm/going_east_04.xpm",
	"resources/xpm/going_east_05.xpm",
	"resources/xpm/going_east_06.xpm",
	"resources/xpm/going_east_07.xpm",
	"resources/xpm/going_east_08.xpm",
	"resources/xpm/going_east_09.xpm",
	"resources/xpm/going_east_10.xpm",
	"resources/xpm/going_east_11.xpm",
	"resources/xpm/going_east_12.xpm",
	"resources/xpm/going_east_13.xpm",
	"resources/xpm/going_east_14.xpm",
	"resources/xpm/going_east_15.xpm",
	"resources/xpm/going_east_16.xpm",
	"resources/xpm/going_east_17.xpm"
},
{
	"resources/xpm/going_north_00.xpm",
	"resources/xpm/going_north_01.xpm",
	"resources/xpm/going_north_02.xpm",
	"resources/xpm/going_north_03.xpm",
	"resources/xpm/going_north_04.xpm",
	"resources/xpm/going_north_05.xpm",
	"resources/xpm/going_north_06.xpm",
	"resources/xpm/going_north_07.xpm",
	"resources/xpm/going_north_08.xpm",
	"resources/xpm/going_north_09.xpm",
	"resources/xpm/going_north_10.xpm",
	"resources/xpm/going_north_11.xpm",
	"resources/xpm/going_north_12.xpm",
	"resources/xpm/going_north_13.xpm",
	"resources/xpm/going_north_14.xpm",
	"resources/xpm/going_north_15.xpm",
	"resources/xpm/going_north_16.xpm",
	"resources/xpm/going_north_17.xpm"
},
{
	"resources/xpm/going_west_00.xpm",
	"resources/xpm/going_west_01.xpm",
	"resources/xpm/going_west_02.xpm",
	"resources/xpm/going_west_03.xpm",
	"resources/xpm/going_west_04.xpm",
	"resources/xpm/going_west_05.xpm",
	"resources/xpm/going_west_06.xpm",
	"resources/xpm/going_west_07.xpm",
	"resources/xpm/going_west_08.xpm",
	"resources/xpm/going_west_09.xpm",
	"resources/xpm/going_west_10.xpm",
	"resources/xpm/going_west_11.xpm",
	"resources/xpm/going_west_12.xpm",
	"resources/xpm/going_west_13.xpm",
	"resources/xpm/going_west_14.xpm",
	"resources/xpm/going_west_15.xpm",
	"resources/xpm/going_west_16.xpm",
	"resources/xpm/going_west_17.xpm"
},
{
	"resources/xpm/going_south_00.xpm",
	"resources/xpm/going_south_01.xpm",
	"resources/xpm/going_south_02.xpm",
	"resources/xpm/going_south_03.xpm",
	"resources/xpm/going_south_04.xpm",
	"resources/xpm/going_south_05.xpm",
	"resources/xpm/going_south_06.xpm",
	"resources/xpm/going_south_07.xpm",
	"resources/xpm/going_south_08.xpm",
	"resources/xpm/going_south_09.xpm",
	"resources/xpm/going_south_10.xpm",
	"resources/xpm/going_south_11.xpm",
	"resources/xpm/going_south_12.xpm",
	"resources/xpm/going_south_13.xpm",
	"resources/xpm/going_south_14.xpm",
	"resources/xpm/going_south_15.xpm",
	"resources/xpm/going_south_16.xpm",
	"resources/xpm/going_south_17.xpm"
},
{
	"resources/xpm/going_east_north_00.xpm",
	"resources/xpm/going_east_north_01.xpm",
	"resources/xpm/going_east_north_02.xpm",
	"resources/xpm/going_east_north_03.xpm",
	"resources/xpm/going_east_north_04.xpm",
	"resources/xpm/going_east_north_05.xpm",
	"resources/xpm/going_east_north_06.xpm",
	"resources/xpm/going_east_north_07.xpm",
	"resources/xpm/going_east_north_08.xpm",
	"resources/xpm/going_east_north_09.xpm",
	"resources/xpm/going_east_north_10.xpm",
	"resources/xpm/going_east_north_11.xpm",
	"resources/xpm/going_east_north_12.xpm",
	"resources/xpm/going_east_north_13.xpm",
	"resources/xpm/going_east_north_14.xpm",
	"resources/xpm/going_east_north_15.xpm",
	"resources/xpm/going_east_north_16.xpm",
	"resources/xpm/going_east_north_17.xpm"
},
{
	"resources/xpm/going_north_west_00.xpm",
	"resources/xpm/going_north_west_01.xpm",
	"resources/xpm/going_north_west_02.xpm",
	"resources/xpm/going_north_west_03.xpm",
	"resources/xpm/going_north_west_04.xpm",
	"resources/xpm/going_north_west_05.xpm",
	"resources/xpm/going_north_west_06.xpm",
	"resources/xpm/going_north_west_07.xpm",
	"resources/xpm/going_north_west_08.xpm",
	"resources/xpm/going_north_west_09.xpm",
	"resources/xpm/going_north_west_10.xpm",
	"resources/xpm/going_north_west_11.xpm",
	"resources/xpm/going_north_west_12.xpm",
	"resources/xpm/going_north_west_13.xpm",
	"resources/xpm/going_north_west_14.xpm",
	"resources/xpm/going_north_west_15.xpm",
	"resources/xpm/going_north_west_16.xpm",
	"resources/xpm/going_north_west_17.xpm"
},
{
	"resources/xpm/going_west_south_00.xpm",
	"resources/xpm/going_west_south_01.xpm",
	"resources/xpm/going_west_south_02.xpm",
	"resources/xpm/going_west_south_03.xpm",
	"resources/xpm/going_west_south_04.xpm",
	"resources/xpm/going_west_south_05.xpm",
	"resources/xpm/going_west_south_06.xpm",
	"resources/xpm/going_west_south_07.xpm",
	"resources/xpm/going_west_south_08.xpm",
	"resources/xpm/going_west_south_09.xpm",
	"resources/xpm/going_west_south_10.xpm",
	"resources/xpm/going_west_south_11.xpm",
	"resources/xpm/going_west_south_12.xpm",
	"resources/xpm/going_west_south_13.xpm",
	"resources/xpm/going_west_south_14.xpm",
	"resources/xpm/going_west_south_15.xpm",
	"resources/xpm/going_west_south_16.xpm",
	"resources/xpm/going_west_south_17.xpm"
},
{
	"resources/xpm/going_south_east_00.xpm",
	"resources/xpm/going_south_east_01.xpm",
	"resources/xpm/going_south_east_02.xpm",
	"resources/xpm/going_south_east_03.xpm",
	"resources/xpm/going_south_east_04.xpm",
	"resources/xpm/going_south_east_05.xpm",
	"resources/xpm/going_south_east_06.xpm",
	"resources/xpm/going_south_east_07.xpm",
	"resources/xpm/going_south_east_08.xpm",
	"resources/xpm/going_south_east_09.xpm",
	"resources/xpm/going_south_east_10.xpm",
	"resources/xpm/going_south_east_11.xpm",
	"resources/xpm/going_south_east_12.xpm",
	"resources/xpm/going_south_east_13.xpm",
	"resources/xpm/going_south_east_14.xpm",
	"resources/xpm/going_south_east_15.xpm",
	"resources/xpm/going_south_east_16.xpm",
	"resources/xpm/going_south_east_17.xpm"
}
};

# define XPM_COLLECT		"resources/xpm/arch.xpm"
# define XPM_EXIT			"resources/xpm/stairs.xpm"
# define XPM_FLOOR			"resources/xpm/floor.xpm"
# define XPM_WALL			"resources/xpm/wall.xpm"

# define VICTORY_MSG		">>> SUCCESS <<<"
# define DEFEAT_MSG			">>> FAILURE <<<"

#endif

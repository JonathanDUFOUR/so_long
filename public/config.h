/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 03:54:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 07:59:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define SLEEP_TIME 21000
/*
**	WARNING /!\
**	Never set SLEEP_TIME value to 0 !!!
*/

# define MAP_CHAR "10CEPDLRU"
/*
**	Must be as followed:
**
**	MAP_CHAR[0]: wall
**	MAP_CHAR[1]: floor
**	MAP_CHAR[2]: collect
**	MAP_CHAR[3]: exit
**	MAP_CHAR[4]: player
**	MAP_CHAR[5]: enemy going down
**	MAP_CHAR[6]: enemy going left
**	MAP_CHAR[7]: enemy going right
**	MAP_CHAR[8]: enemy going up
*/

# define COLLECT_XPM "ressources/xpm/arch.xpm"
# define ENEMY_DOWN_XPM "ressources/xpm/spike_down.xpm"
# define ENEMY_LEFT_XPM "ressources/xpm/spike_left.xpm"
# define ENEMY_RIGHT_XPM "ressources/xpm/spike_right.xpm"
# define ENEMY_UP_XPM "ressources/xpm/spike_up.xpm"
# define EXIT_XPM "ressources/xpm/stairs.xpm"
# define FLOOR_XPM "ressources/xpm/floor.xpm"
# define PLAYER_DOWN_XPM "ressources/xpm/penguin_down.xpm"
# define PLAYER_LEFT_XPM "ressources/xpm/penguin_left.xpm"
# define PLAYER_RIGHT_XPM "ressources/xpm/penguin_right.xpm"
# define PLAYER_UP_XPM "ressources/xpm/penguin_up.xpm"
# define WALL_XPM "ressources/xpm/wall.xpm"

# define WIN_TITLE "so_long"

# define VICTORY_MSG ">>> SUCCESS <<<"
# define DEFEAT_MSG ">>> FAILURE <<<"

# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define WHITE "\e[0m"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 03:54:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/01 00:16:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define MAP_CHAR "10CEP"
/*
**	Must be as followed : <wall> <floor> <collect> <exit> <player>
*/

# define COLLECT_XPM "ressources/xpm/arch.xpm"
# define EXIT_XPM "ressources/xpm/stairs.xpm"
# define FLOOR_XPM "ressources/xpm/floor.xpm"
# define PLAYER_DOWN_XPM "ressources/xpm/penguin_down.xpm"
# define PLAYER_LEFT_XPM "ressources/xpm/penguin_left.xpm"
# define PLAYER_RIGHT_XPM "ressources/xpm/penguin_right.xpm"
# define PLAYER_UP_XPM "ressources/xpm/penguin_up.xpm"
# define WALL_XPM "ressources/xpm/wall.xpm"

# define WIN_TITLE "so_long"

# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define WHITE "\e[0m"

#endif

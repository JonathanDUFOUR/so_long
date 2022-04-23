/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_config.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:53:51 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 10:46:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CONFIG_H
# define T_CONFIG_H

# include "t_img.h"
# include "t_xptr.h"

typedef struct s_config	t_config;

struct s_config
{
	t_img	enemy[4];
	t_img	exit;
	t_img	floor;
	t_img	player[8];
	t_img	wall;
};

int		config_load(t_config *const c, t_xptr const *const x, int *const ret)
		__attribute__((nonnull));
int		config_load_enemy(t_config *const c, t_xptr const *const x,
			int *const ret)
		__attribute__((nonnull));
int		config_load_exit(t_config *const c, t_xptr const *const x,
			int *const ret)
		__attribute__((nonnull));
int		config_load_floor(t_config *const c, t_xptr const *const x,
			int *const ret)
		__attribute__((nonnull));
int		config_load_player(t_config *const c, t_xptr const *const x,
			int *const ret)
		__attribute__((nonnull));
int		config_load_wall(t_config *const c, t_xptr const *const x,
			int *const ret)
		__attribute__((nonnull));

void	config_clear(t_config *const c, t_xptr const *const x)
		__attribute__((nonnull));

#endif

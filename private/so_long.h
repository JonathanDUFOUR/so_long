/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:50:45 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/06 21:56:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "t_all.h"

int		arg_check(int const ac, char const **av, int *const ret)
		__attribute__((nonnull));
int		event_none(t_all *const a)
		__attribute__((nonnull));
int		hook_init(t_all *const a, int *const ret)
		__attribute__((nonnull));
int		hook_key_press(int const keysym, t_all *const a)
		__attribute__((nonnull));
int		hook_key_release(int const keysym, t_all *const a)
		__attribute__((nonnull));
int		render(t_all *const a)
		__attribute__((nonnull));

void	err_msg(int const err);
void	game_over(char const *const msg, double const distance,
			t_xptr const *const x)
		__attribute__((nonnull));

#endif

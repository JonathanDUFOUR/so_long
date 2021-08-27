/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:56:13 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/27 04:12:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "err_msg_lookup.h"

int	sl_err_msg(int err)
{
	int	i;

	write(2, "\e[31mError\n", 11);
	i = 0;
	while (g_err[i].msg && err != g_err[i].err)
		++i;
	write(2, g_err[i].msg, g_err[i].len);
	write(2, "\e[0m\n", 5);
	return (err);
}

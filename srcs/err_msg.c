/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:56:13 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 05:20:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_colors.h"
#include "lookup_err_msg.h"

/**
	@brief	Print an explicit error message on stderr.

	@param	err The error code.
*/
void	err_msg(int const err)
{
	int	i;

	write(STDERR_FILENO, RED"Error\n", 11);
	i = 0;
	while (g_err[i].msg && err != g_err[i].err)
		++i;
	write(STDERR_FILENO, g_err[i].msg, g_err[i].len);
	write(STDERR_FILENO, RESET"\n", 5);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fddel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 00:56:40 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 04:33:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

/*
	Close the pointed file descriptor by the given pointer `fd`
	and set its value to -1
	In case of a negative pointed file descriptor, do nothing
*/
int	ft_fddel(int *const fd)
{
	if (*fd < 0)
		return (EXIT_SUCCESS);
	if (close(*fd) == -1)
		return (EXIT_FAILURE);
	*fd = -1;
	return (EXIT_SUCCESS);
}

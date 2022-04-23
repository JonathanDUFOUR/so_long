/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 03:25:00 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/12 05:19:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "e_ret.h"

/**
	@brief	Check if the arguments are correct.

	@param	ac The argument count.
	@param	av The argument values.
	@param	ret The program status reference.

	@return	The updated program status.
*/
int	arg_check(int const ac, char const **av, int *const ret)
{
	char const	*basename;
	size_t		len;

	if (ac != 2)
		return (*ret = AC_ERR);
	basename = ft_strrchr(av[1], '/');
	if (!basename)
		basename = av[1];
	else
		basename++;
	len = ft_strlen(basename);
	if (len < 5 || ft_strcmp(basename + len - 4, ".ber"))
		return (*ret = EXT_ERR);
	return (*ret = SUCCESS);
}

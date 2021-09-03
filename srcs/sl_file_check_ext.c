/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_file_check_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 06:28:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/03 06:48:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_string.h"
#include "enum/e_ret.h"

/*
**	return an error if the file extension is not ".ber"
*/
int	sl_file_check_ext(char const *file)
{
	char	*s;
	size_t	len;

	s = ft_strrchr(file, '/');
	if (s)
		file = s + 1;
	len = ft_strlen(file);
	if (len < 5
		|| file[len - 1] != 'r'
		|| file[len - 2] != 'e'
		|| file[len - 3] != 'b'
		|| file[len - 4] != '.')
		return (EXT_ERR);
	return (SUCCESS);
}

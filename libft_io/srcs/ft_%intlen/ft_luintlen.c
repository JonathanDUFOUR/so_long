/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_luintlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:26:41 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:07:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int.h"

/*
	Return the length of the given t_luint `nb`
*/
t_uint	ft_luintlen(t_luint nb)
{
	t_uint	len;

	len = 1;
	while (nb / 10)
	{
		++len;
		nb /= 10;
	}
	return (len);
}

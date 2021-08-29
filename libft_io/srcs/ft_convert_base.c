/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:21:58 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/22 20:02:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*ft_convert_base(char const *n,
	char const *base_from, char const *base_to)
{
	if (!n || ft_wrong_base(base_from) || ft_wrong_base(base_to))
		return (NULL);
	return (ft_itoa_base(ft_atoi_base(n, base_from), base_to));
}

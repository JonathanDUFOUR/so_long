/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:02:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/22 23:03:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ptf_strlen(char const *s)
{
	register char const	*p = s;

	while (*p)
		++p;
	return (p - s);
}

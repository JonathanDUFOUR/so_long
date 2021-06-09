/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:27:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/09 16:55:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"

char	*sl_strjoin(char const *s1, char const *s2)
{
	char	*output;
	char	*ptr;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	len = 0;
	if (s1)
		len = sl_strlen(s1);
	if (s2)
		len += sl_strlen(s2);
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ptr = output;
	while (s1 && *s1)
		*ptr++ = *s1++;
	while (s2 && *s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (output);
}

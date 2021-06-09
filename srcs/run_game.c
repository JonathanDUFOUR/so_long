/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:57:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/09 15:07:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	run_game(char *file)
{
	int		dim[2];
	char	*map;
	int		ret;

	ret = get_map(file, &map);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}

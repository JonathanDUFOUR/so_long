/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg_lookup.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:56:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/30 00:49:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_LOOKUP_H
# define ERR_MSG_LOOKUP_H

# include <stddef.h>
# include "enum/e_ret.h"

typedef struct s_err	t_err;

struct	s_err
{
	int			err;
	char const	*msg;
	size_t		len;
};

static t_err const		g_err[] = {
	{AC_ERR, "wrong argument count", 20},
	{OPEN_ERR, "open() failed", 13},
	{GNL_ERR, "get_next_line() failed", 22},
	{MAP_ERR, "invalid map", 11},
	{MLX_ERR, "mlx function failed", 19},
	{IMG_DIM_ERR, "invalid image dimensions", 24},
	{NO_HOOK_ERR, "no hook set for the pressed key", 31},
	{0, NULL, 0}
};

#endif

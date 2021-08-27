/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg_lookup.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:56:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/27 04:05:11 by jodufour         ###   ########.fr       */
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

static t_err const	g_err[] = {
	{AC_ERR, "Wrong argument count", 20},
	{0, NULL, 0}
};

#endif

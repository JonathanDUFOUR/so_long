/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 02:18:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/15 01:16:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LST_H
# define T_LST_H

# include <string.h>

typedef struct s_lst	t_lst;

struct s_lst
{
	void	*head;
	void	*tail;
	size_t	size;
};

t_lst	*sl_get_lst(void);

#endif

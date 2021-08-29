/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_ret.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 03:54:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/29 20:25:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_RET_H
# define E_RET_H

enum	e_ret
{
	GNL_ERR = -1,
	SUCCESS,
	AC_ERR,
	OPEN_ERR,
	MAP_ERR,
	MLX_ERR,
	IMG_DIM_ERR
};

#endif

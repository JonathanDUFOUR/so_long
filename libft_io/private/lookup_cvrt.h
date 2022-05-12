/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_cvrt.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 04:09:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/05/02 17:13:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_CVRT_H
# define LOOKUP_CVRT_H

# include <stdarg.h>
# include "t_ctx.h"

typedef struct s_cvrt	t_cvrt;
typedef void			(*t_fct)(t_ctx *const ctx, va_list va);

struct s_cvrt
{
	char const	c;
	t_fct const	fct;
};

void	cvrt_c(t_ctx *const ctx, va_list va);
void	cvrt_s(t_ctx *const ctx, va_list va);
void	cvrt_p(t_ctx *const ctx, va_list va);
void	cvrt_d(t_ctx *const ctx, va_list va);
void	cvrt_u(t_ctx *const ctx, va_list va);
void	cvrt_x_lower(t_ctx *const ctx, va_list va);
void	cvrt_x_upper(t_ctx *const ctx, va_list va);
void	cvrt_o(t_ctx *const ctx, va_list va);
void	cvrt_b(t_ctx *const ctx, va_list va);
void	cvrt_prct(t_ctx *const ctx, va_list va __attribute__((unused)));

static t_cvrt const		g_cvrt[] = {
{'c', cvrt_c},
{'s', cvrt_s},
{'p', cvrt_p},
{'d', cvrt_d},
{'i', cvrt_d},
{'u', cvrt_u},
{'x', cvrt_x_lower},
{'X', cvrt_x_upper},
{'o', cvrt_o},
{'b', cvrt_b},
{'%', cvrt_prct},
{0}
};

#endif

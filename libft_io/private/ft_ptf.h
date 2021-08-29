/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 01:09:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/18 02:37:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PTF_H
# define FT_PTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <string.h>
# include <wchar.h>
# include "type/t_int.h"

/*
**	(1 << 0) -> '-'
**	(1 << 1) -> '0'
**	(1 << 2) -> '+'
**	(1 << 3) -> ' '
**	(1 << 4) -> '#'
**
**	(1 << 5) -> l
**	(1 << 6) -> ll
**	(1 << 7) -> h
**	(1 << 8) -> hh
*/
# define FLAG_CHARS	"-0+ #"

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	uint16_t	flags;
	t_uint		len;
	t_uint		fwidth;
	t_uint		prec;
	bool		precised;
};

enum	e_padding_side
{
	LEFT,
	RIGHT,
	NONE
};

enum	e_style
{
	LOWER,
	UPPER
};

/*****************************************************************************/
/*                                 UNIVERSAL                                 */
/*****************************************************************************/
int			padding(int c, t_uint padlen);

char		*ptf_strchr(const char *s, int c);

char const	*mng_arg(char const *format, t_ctx *ctx, va_list va);
char const	*mng_flags(char const *format, t_ctx *ctx);
char const	*mng_fwidth(char const *format, t_ctx *ctx, va_list va);
char const	*mng_prec(char const *format, t_ctx *ctx, va_list va);
char const	*mng_lmod(char const *format, t_ctx *ctx);
char const	*mng_spec(char const *format, t_ctx *ctx, va_list va);
char const	*mng_text(char const *format, t_ctx *ctx);

size_t		ptf_strlen(char const *s);

/*****************************************************************************/
/*                               %% CONVERSION                               */
/*****************************************************************************/
int			padded_putprct(uint16_t flags, t_uint padlen);

/*****************************************************************************/
/*                               %B CONVERSION                               */
/*****************************************************************************/
int			padded_putlluint_bin(t_lluint n, uint32_t len, t_ctx *ctx);

void		putlluint_bin(t_lluint n);

t_uint		blen(t_lluint n);

/*****************************************************************************/
/*                               %C CONVERSION                               */
/*****************************************************************************/
int			padded_putchar(char c, uint16_t flags, t_uint padlen);
int			padded_putwchar(wchar_t c, uint16_t flags, t_uint padlen);

t_uint		wclen(wchar_t c);

/*****************************************************************************/
/*                               %D CONVERSION                               */
/*****************************************************************************/
int			padded_putllint(t_llint n, t_uint len, t_ctx *ctx);

void		flag_exception(t_ctx *ctx);

t_uint		dlen(t_llint n);

/*****************************************************************************/
/*                               %O CONVERSION                               */
/*****************************************************************************/
int			padded_putlluint_oct(t_lluint n, t_uint len, t_ctx *ctx);

void		putlluint_oct(t_lluint n);

t_uint		olen(t_lluint n);

/*****************************************************************************/
/*                               %P CONVERSION                               */
/*****************************************************************************/
int			padded_putaddr(uintptr_t n, t_uint len, t_ctx *ctx);

t_uint		plen(uintptr_t n);

/*****************************************************************************/
/*                               %S CONVERSION                               */
/*****************************************************************************/
int			putnull(t_ctx *ctx);
int			padded_putnstr(char *s, t_ctx *ctx);
int			padded_putnwstr(wchar_t *s, t_ctx *ctx, t_uint len, t_uint size);

t_uint		wstrlen(wchar_t *s);
t_uint		wstrsize(wchar_t *s);

/*****************************************************************************/
/*                               %U CONVERSION                               */
/*****************************************************************************/
int			padded_putlluint(t_lluint n, t_uint len, t_ctx *ctx);

t_uint		ulen(t_lluint n);

/*****************************************************************************/
/*                           %X AND %P CONVERSIONS                           */
/*****************************************************************************/
int			padded_putlluint_hexa(t_lluint n, uint32_t len, t_ctx *ctx,
				int style);

void		putlluint_hexa(t_lluint n, char c);

t_uint		xlen(t_lluint n);

#endif

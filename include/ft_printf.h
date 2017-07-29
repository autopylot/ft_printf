/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:19:24 by wlin              #+#    #+#             */
/*   Updated: 2017/07/29 12:17:16 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>
# include <wchar.h>

#define F_FLAG(x)	(x == '-' || x == '#' || x == ' ' || x == '0' || x == '+')
#define F_NUM(x)	((x >= '0' && x <= '9') || x == '.')
#define F_LEN(x) 	(x == 'h' || x == 'l' || x == 'j' || x == 'z')

#define F_SPEC(x)	(F_CHR(x) || F_SINT(x) || F_UINT(x))
#define F_CHR(x)	(x == 's' || x == 'S' || x == 'c' || x == 'C')
#define F_SINT(x)	(x == 'd' || x == 'D' || x == 'i')
#define F_UINT(x)	(x == 'u' || x == 'o' || x == 'x' || x == 'p' || F_UPINT(x))
#define	F_UPINT(x)	(x == 'X' || x == 'U' || x == 'O')
#define PREFIX(x) 	(x == 'X' ? "0X" : "0x")

/*
** hh = 1	:	unsigned char
** h  = 2	:	unsigned short
** l  = 3	:	long
** ll = 4	:	long long
** z  = 5	:	size_t
** j  = 6	:	intmax_t
*/

typedef struct	s_fmt_spec
{
	bool		pad;
	bool		left;
	bool		plus;
	bool 		space;
	bool		prefix;
	int			width;
	int 		precision;
	int			length;
	char		spec;
	intmax_t	sints;
	uintmax_t	uints;
	char		*buffer;
}				t_fmt_spec;

typedef struct	s_printf
{
	int			len;
	va_list		ap;
	t_fmt_spec	fspec;
}				t_printf;


int		ft_printf(const char *format,...);
void 	init(t_fmt_spec *fspec);
void	parse_fspec(t_printf *pf, const char **fmt);
int 	pdispatch(t_printf *pf);
int 	fetch_spec(t_printf *pf);
void 	format_precision(t_printf *pf);
void 	format_prefix(t_printf *pf);
void 	format_width(t_printf *pf);
void 	format_space(t_printf *pf);
void 	format_plus(t_printf *pf);
void 	format_left(t_printf *pf);
void 	pad_zero(t_printf *pf, int pad, char c);
char 	*set_wide(wchar_t c);
char 	*set_wstr(wchar_t *wstr);
void 	print_format(t_printf *pf);
void 	insert_substring(char *a, char *b, int position);
char 	*substring(char *string, int position, int length);
char 	*uitoa_base(t_printf *pf, int base);
char 	*sitoa_base(t_printf *pf, int base);

#endif

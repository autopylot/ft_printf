/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 19:25:20 by wlin              #+#    #+#             */
/*   Updated: 2017/07/19 20:33:21 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *set_wide(wchar_t c)
{
    char *b_static;
    char* b;

	b_static = ft_strnew(4);
	b = b_static;
    if (c<(1<<7))
        *b++ = (char)(c);
    else if (c<(1<<11))
    {
        *b++ = (char)((c>>6)|0xC0);
        *b++ = (char)((c&0x3F)|0x80);
    }
    else if (c<(1<<16))
        {
        *b++ = (char)(((c>>12))|0xE0);
        *b++ =  (char)(((c>>6)&0x3F)|0x80);
        *b++ =  (char)((c&0x3F)|0x80);
    }
    else if (c<(1<<21))
    {
        *b++ = (char)(((c>>18))|0xF0);
        *b++ = (char)(((c>>12)&0x3F)|0x80);
        *b++ = (char)(((c>>6)&0x3F)|0x80);
        *b++ = (char)((c&0x3F)|0x80);
    }
    *b = '\0';
    return (b_static);
}

static char *set_wstr(wchar_t *wstr)
{
	char *s;
	char *tmp;

	if (s == 0)
		s = ft_strnew(1);
	while (*wstr)
	{
		tmp = set_wide(*wstr++);
		s = strjoin_f(s, tmp, 'B');
	}
	return (s);
}

static intmax_t fetch_signed(t_printf *pf)
{
	if (pf->fspec.length == 0 && pf->fspec.spec != 'D')
		return (va_arg(pf->ap, int));
	else if (pf->fspec.length == 1)
		return ((char)va_arg(pf->ap, unsigned int));
	else if (pf->fspec.length == 2)
		return ((short)va_arg(pf->ap, unsigned int));
	else if (pf->fspec.length == 3 || pf->fspec.spec == 'D')
		return (va_arg(pf->ap, long));
	else if (pf->fspec.length == 4)
		return (va_arg(pf->ap, long long));
	else if (pf->fspec.length == 5)
		return (va_arg(pf->ap, intmax_t));
	else if (pf->fspec.length == 6)
	 	return (va_arg(pf->ap, size_t));
	return (0);
}

static uintmax_t fetch_unsigned(t_printf *pf)
{
	if (pf->fspec.length == 0 && !F_UPINT(pf->fspec.spec))
		return (va_arg(pf->ap, unsigned int));
	else if (pf->fspec.length == 1)
		return ((unsigned char)va_arg(pf->ap, unsigned int));
	else if (pf->fspec.length == 2)
		return ((unsigned short)va_arg(pf->ap, unsigned int));
	else if (pf->fspec.length == 3 || F_UPINT(pf->fspec.spec))
		return (va_arg(pf->ap, unsigned long));
	else if (pf->fspec.length == 4)
		return (va_arg(pf->ap, unsigned long long));
	else if (pf->fspec.length == 5)
		return (va_arg(pf->ap, uintmax_t));
	else if (pf->fspec.length == 6)
		return (va_arg(pf->ap, size_t));
	return (0);
}


static char *fetch_char(t_printf *pf)
{
	char *s;

	if (pf->fspec.length == 0)
	{
		if (pf->fspec.spec == 'c')
		{
			s = ft_strnew(1);
			s[0] = va_arg(pf->ap, int);
			return (s);
		}
		else if (pf->fspec.spec == 'C')
			return (set_wide(va_arg(pf->ap, wchar_t)));
		else if (pf->fspec.spec == 's')
			return (ft_strdup((va_arg(pf->ap, char*))));
		else if (pf->fspec.spec == 'S')
			return (set_wstr(va_arg(pf->ap, wchar_t*)));
	}
	else if (pf->fspec.length == 3 )
	{
		if (pf->fspec.spec == 'c')
			return (set_wide(va_arg(pf->ap, wchar_t)));
		else if (pf->fspec.spec == 's')
			return (set_wstr(va_arg(pf->ap, wchar_t*)));
	}
	return (NULL);
}

int fetch_spec(t_printf *pf)
{
	if (pf->fspec.spec == 'p')
	{
		if (pf->fspec.length != 0)
			return (0);
		pf->fspec.uints = fetch_unsigned(pf);
		pf->fspec.buffer = uitoa_base(pf, 16);
		return (1);
	}
	else if (F_SINT(pf->fspec.spec))
	{
		pf->fspec.sints = fetch_signed(pf);
		pf->fspec.buffer = sitoa_base(pf, 10);
		return (1);
	}
	else if (F_UINT(pf->fspec.spec))
	{
		pf->fspec.uints = fetch_unsigned(pf);
		if (pf->fspec.spec == 'x' || pf->fspec.spec == 'X')
			pf->fspec.buffer = uitoa_base(pf, 16);
		else if (pf->fspec.spec == 'o' || pf->fspec.spec == 'O')
			pf->fspec.buffer = uitoa_base(pf, 8);
		else if (pf->fspec.spec == 'u' || pf->fspec.spec == 'U')
			pf->fspec.buffer = uitoa_base(pf, 10);
		return (1);
	}
	else if (F_CHR(pf->fspec.spec))
	{
		if (!(pf->fspec.buffer = fetch_char(pf)))
			return (0);
		return (1);
	}
	return (0);
}

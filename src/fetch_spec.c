/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 19:25:20 by wlin              #+#    #+#             */
/*   Updated: 2017/07/29 21:18:39 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t fetch_signed(t_printf *pf)
{
	if (pf->fspec.length == 0 && pf->fspec.spec != 'D')
		return (va_arg(pf->ap, int));
	else if (pf->fspec.length == 3 || pf->fspec.spec == 'D')
		return (va_arg(pf->ap, long));
	else if (pf->fspec.length == 1)
		return ((char)va_arg(pf->ap, unsigned int));
	else if (pf->fspec.length == 2)
		return ((short)va_arg(pf->ap, unsigned int));
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
	if (pf->fspec.spec == 'p')
		return ((uintmax_t)va_arg(pf->ap, void*));
	if (pf->fspec.length == 0 && !F_UPINT(pf->fspec.spec))
		return (va_arg(pf->ap, unsigned int));
	else if (pf->fspec.length == 3 || F_UPINT(pf->fspec.spec))
		return (va_arg(pf->ap, unsigned long));
	else if (pf->fspec.length == 1)
		return ((unsigned char)va_arg(pf->ap, unsigned int));
	else if (pf->fspec.length == 2)
		return ((unsigned short)va_arg(pf->ap, unsigned int));
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
		if (pf->fspec.spec == 'c' || pf->fspec.spec == 'C')
		{
			s = ft_strnew(1);
			s[0] = va_arg(pf->ap, int);
			return (s);
		}
		else if (pf->fspec.spec == 's' || pf->fspec.spec == 'S')
			return (ft_strdup((va_arg(pf->ap, char*))));
		// else if (pf->fspec.spec == 'S')
		// 	return (set_wstr(va_arg(pf->ap, wchar_t*)));
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

void fetch_spec(t_printf *pf)
{
	// if (pf->fspec.spec == 'p' && pf->fspec.length != 0)
	// 	return (0);
	if (F_SINT(pf->fspec.spec))
	{
		pf->fspec.sints = fetch_signed(pf);
		pf->fspec.buffer = sitoa_base(pf, 10);
	}
	else if (F_UINT(pf->fspec.spec))
	{
		pf->fspec.uints = fetch_unsigned(pf);
		if (pf->fspec.spec == 'x' || pf->fspec.spec == 'X' || pf->fspec.spec == 'p')
			pf->fspec.buffer = uitoa_base(pf, 16);
		else if (pf->fspec.spec == 'o' || pf->fspec.spec == 'O')
			pf->fspec.buffer = uitoa_base(pf, 8);
		else if (pf->fspec.spec == 'u' || pf->fspec.spec == 'U')
			pf->fspec.buffer = uitoa_base(pf, 10);
	}
	else if (F_CHR(pf->fspec.spec))
		pf->fspec.buffer = fetch_char(pf);
}

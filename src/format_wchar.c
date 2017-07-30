/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:21:09 by wlin              #+#    #+#             */
/*   Updated: 2017/07/29 21:14:25 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *set_wide(wchar_t c)
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

char *set_wstr(wchar_t *wstr)
{
	char *s;
	char *tmp;

	s = ft_strnew(1);
	while (*wstr)
	{
		tmp = set_wide(*wstr++);
		s = strjoin_f(s, tmp, 'B');
	}
	return (s);
}

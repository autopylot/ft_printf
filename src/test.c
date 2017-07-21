/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 15:26:01 by wlin              #+#    #+#             */
/*   Updated: 2017/07/20 14:47:38 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include "ft_printf.h"

// int ft_isupper(int c)
// {
// 	if (c >= 'A' && c <= 'Z')
// 		return (1);
// 	return (0);
// }
//
// long ft_strtol(const char *nptr, char **endptr, register int base)
// {
// 	register const char *s = nptr;
// 	register unsigned long acc;
// 	register int c;
// 	register unsigned long cutoff;
// 	register int neg = 0, any, cutlim;
//
// 	do {
// 		c = *s++;
// 	} while (WS(c));
// 	if (c == '-') {
// 		neg = 1;
// 		c = *s++;
// 	} else if (c == '+')
// 		c = *s++;
// 	if ((base == 0 || base == 16) &&
// 	    c == '0' && (*s == 'x' || *s == 'X')) {
// 		c = s[1];
// 		s += 2;
// 		base = 16;
// 	}
// 	if (base == 0)
// 		base = c == '0' ? 8 : 10;
// 	cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
// 	cutlim = cutoff % (unsigned long)base;
// 	cutoff /= (unsigned long)base;
// 	for (acc = 0, any = 0;; c = *s++) {
// 		if (ft_isdigit(c))
// 			c -= '0';
// 		else if (ft_isalpha(c))
// 			c -= ft_isupper(c) ? 'A' - 10 : 'a' - 10;
// 		else
// 			break;
// 		if (c >= base)
// 			break;
// 		if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
// 			any = -1;
// 		else {
// 			any = 1;
// 			acc *= base;
// 			acc += c;
// 		}
// 	}
// 	if (any < 0) {
// 		acc = neg ? LONG_MIN : LONG_MAX;
// 		errno = ERANGE;
// 	} else if (neg)
// 		acc = -acc;
// 	if (endptr != 0)
// 		*endptr = (char *) (any ? s - 1 : nptr);
// 	return (acc);
// }
//
// int format_oct(char *octal)
// {
//
// }
//
// void set_wide(char *dst, wchar_t wide)
// {
// 	char *oct = ft_itoa_base(wide, 8)
//
// 	if (ft_atoi(oct) < 200)
// 		dst[0] = ft_strtol(oct, NULL, 8);
// 	else if (ft_atoi(oct) < 4000)
// 	{
// 		dst[0] =
// 		dst[1] =
// 	}
// 	else if (ft_atoi(oct) < 200000)
// 	{
//
// 	}
// 	else
// 	{
//
// 	}
//
// }
//
//
// int main()
// {
// 	wchar_t wchr = L'€';
//
//
// 	char a= 0342;
// 	char b = 0202;
// 	char c = 0254;
// 	printf("%c%c%c\n", a, b, c);
// 	printf("%s\n", ft_itoa_base(wchr, 8));
//
// 	return (0);
// }

int main()
{

	printf("This is a -%-5d-\n", 10);
	printf("This is a -%- 7.1d-\n", 6);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_itoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:13:23 by wlin              #+#    #+#             */
/*   Updated: 2017/07/20 11:40:02 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *sitoa_base(t_printf *pf, int base)
{
	int len;
	char *s;
	intmax_t tmp;
	intmax_t nbr;

	tmp = pf->fspec.sints;
	nbr = tmp;
	len = (nbr < 0 && base == 10 ? 2 : 1);
	while (nbr && ++len)
		nbr /= 10;
	if (!(s = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	s[--len] = '\0';
	if (tmp < 0 && base == 10)
		s[0] = '-';
	while ((tmp = ABS(tmp)))
	{
		s[--len] = (tmp % base > 9 ? tmp % base - 10 + 'a' : tmp % base + '0');
		tmp /= base;
	}
	return (s);
}

char *uitoa_base(t_printf *pf, int base)
{
	int len;
	char *s;
	uintmax_t nbr;
	uintmax_t tmp;


	tmp = pf->fspec.uints;
	nbr = tmp;
	len = 1;
	while (nbr && ++len)
		nbr /= base;
	if (!(s = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	s[--len] = '\0';
	while (tmp)
	{
		s[--len] = (tmp % base > 9 ? tmp % base - 10 + 'a' : tmp % base + '0');
		tmp /= base;
	}
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:13:23 by wlin              #+#    #+#             */
/*   Updated: 2017/07/31 14:42:04 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *sitoa_base(t_printf *pf, int base)
{
	char		*s;
	int			len;
	int			rem;
	intmax_t	tmp;
	intmax_t	nbr;

	if (base < 2 || base > 16)
		return (NULL);
	tmp = pf->fspec.sints;
	nbr = tmp;
	if (tmp == 0)
		return (ft_strdup("0"));
	len = (pf->fspec.sints < 0 && base == 10 ? 2 : 1);
	while (nbr /= base)
		++len;
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (tmp)
	{
		rem = ABS((tmp % base));
		s[--len] = (rem > 9 ? rem - 10 + 'a' : rem + '0');
		tmp = ABS((tmp / base));
	}
	if (pf->fspec.sints < 0)
		s[--len] = '-';
	return (s);
}

char *uitoa_base(t_printf *pf, int base)
{
	int len;
	char *s;
	char c;
	uintmax_t nbr;
	uintmax_t tmp;

	len = 1;
	if (base < 2 || base > 16)
		return (NULL);
	c = (pf->fspec.spec == 'X' ? 'A' : 'a');
	tmp = pf->fspec.uints;
	nbr = tmp;
	if (tmp == 0)
		return (ft_strdup("0"));
	while (nbr /= base)
		++len;
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (tmp)
	{
		s[--len] = (tmp % base > 9 ? tmp % base - 10 + c : tmp % base + '0');
		tmp /= base;
	}
	return (s);
}

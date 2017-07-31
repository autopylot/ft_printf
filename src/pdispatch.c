/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdispatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:03:17 by wlin              #+#    #+#             */
/*   Updated: 2017/07/31 12:02:17 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void format_address(t_printf *pf)
{
	pf->fspec.buffer = strjoin_f("0x", pf->fspec.buffer, 'R');
}

void pdispatch(t_printf *pf)
{
	int i;

	i = 0;
	fetch_spec(pf);
	if (pf->fspec.spec == 'p')
		format_address(pf);
	if (pf->fspec.precision > -1)
		format_precision(pf);
	if (pf->fspec.width)
		format_width(pf);
	if (pf->fspec.prefix)
		format_prefix(pf);
	if (pf->fspec.space)
		format_space(pf);
	if (pf->fspec.plus)
		format_plus(pf);
	if (pf->fspec.left)
		format_left(pf);
	while (pf->fspec.buffer[i])
	{
			ft_putchar(pf->fspec.buffer[i++]);
			++pf->len;
	}
	// ft_putstr(pf->fspec.buffer);
	// pf->len += ft_strlen(pf->fspec.buffer);
	//return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdispatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:03:17 by wlin              #+#    #+#             */
/*   Updated: 2017/07/31 20:00:54 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pdispatch(t_printf *pf)
{
	int i;

	i = -1;
	fetch_spec(pf);
	if (pf->fspec.spec == 'p')
		pf->fspec.buffer = strjoin_f("0x", pf->fspec.buffer, 'R');
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
	while (pf->fspec.buffer[++i])
	{
		ft_putchar(pf->fspec.buffer[i]);
		if ((pf->fspec.spec == 'c' || pf->fspec.spec == 's') && pf->fspec.length == 3)
		{
			if (i % 4 == 0)
				++pf->len;
		}
		else
			++pf->len;
	}
}

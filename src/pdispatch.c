/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdispatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:03:17 by wlin              #+#    #+#             */
/*   Updated: 2017/08/01 14:38:59 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pdispatch(t_printf *pf)
{
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
	ft_putstr(pf->fspec.buffer);
	if (*(pf->fspec.buffer))
		pf->len += ft_strlen(pf->fspec.buffer);
	else
		pf->len += pf->fspec.width;
}

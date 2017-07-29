/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdispatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:03:17 by wlin              #+#    #+#             */
/*   Updated: 2017/07/26 11:32:30 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Prints tag struct and dispatch matching functions
*/
int pdispatch(t_printf *pf)
{
	fetch_spec(pf);
	if (pf->fspec.precision)
		format_precision(pf);
	if (pf->fspec.width)
		format_width(pf);
	if (pf->fspec.prefix || pf->fspec.spec == 'p')
		format_prefix(pf);
	if (pf->fspec.space)
		format_space(pf);
	if (pf->fspec.plus)
		format_plus(pf);
	if (pf->fspec.left)
		format_left(pf);
	ft_putstr(pf->fspec.buffer);
	pf->len += ft_strlen(pf->fspec.buffer);
	return (1);
}

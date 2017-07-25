/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdispatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:03:17 by wlin              #+#    #+#             */
/*   Updated: 2017/07/25 11:55:22 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Prints tag struct and dispatch matching functions
*/
int pdispatch(t_printf *pf)
{
	if (!fetch_spec(pf))
		return (0);
	if (!format_precision(pf))
		return (0);
	if (!format_width(pf))
		return (0);
	// if (!format_prefix(pf))
	// 	return (0);
	// if (!format_space(pf))
	// 	return (0);
	// if (!format_plus(pf))
	// 	return (0);
	if (!format_left(pf))
		return (0);
	// if (pad)
	ft_putstr(pf->fspec.buffer);
	// move buffer to pf buffer
	//print_format(pf);
	return (1);
}

int ndispatch(t_printf *pf)
{
	if (pf->fspec.spec == 'D' && pf->fspec.length != 0)
		return (0);
	fetch_spec(pf);
	if (!format_precision(pf))
		return (0);
	format_width(pf);
	if (!pf->fspec.plus && pf->fspec.space)

	if (!pf->fspec.left && pf->fspec.pad)

	if (pf->fspec.plus && F_SINT(pf->fspec.spec))

	if (pf->fspec.space && F_SINT(pf->fspec.spec))
}

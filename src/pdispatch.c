/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdispatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:03:17 by wlin              #+#    #+#             */
/*   Updated: 2017/07/20 14:34:28 by wlin             ###   ########.fr       */
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
	if (pf->fspec.precision > -1)
		fmt_precision(pf);
	if (pf->fspec.p_width)
		fetch_width(pf);
	if (pf->fspec.pad_zero && !(pf->fspec.precision > -1))
		ft_replchr(pf->fspec.buffer, ' ', '0');
	if (pf->fspec.prefix)
		format_prefix(pf);
	if (format_space(pf))
		;
	if (format_plus(pf))
		;
	printf("This is a -%s- len: %zu\n", pf->fspec.buffer, ft_strlen(pf->fspec.buffer));
	//
	// if (pf->prefix)

	// move buffer to pf buffer
	// reinint struct
	return (1);
}

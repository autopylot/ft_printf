/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:45:50 by wlin              #+#    #+#             */
/*   Updated: 2017/07/29 12:19:22 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void format_width(t_printf *pf)
{
	char c;
	int pad;

	if (((pad = pf->fspec.width - ft_strlen(pf->fspec.buffer)) > 0))
	{
		c = ' ';
		if (pf->fspec.precision == -1 && !pf->fspec.left && pf->fspec.pad)
		{
			if (F_SINT(pf->fspec.spec) || F_UINT(pf->fspec.spec))
				c = '0';
		}
		pad_zero(pf, pad, c);
	}
}

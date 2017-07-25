/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:45:50 by wlin              #+#    #+#             */
/*   Updated: 2017/07/20 20:42:00 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int format_width(t_printf *pf)
{
	char *s;
	char c;
	int pad;

	if (((pad = pf->fspec.width - ft_strlen(pf->fspec.buffer)) > 0))
	{
		c = ' ';
		if (pf->fspec.precision == -1 && pf->fspec.pad)
			c = '0';
		if (pf->fspec.left)
			c = ' ';
		s = ft_strnew(pad);
		pad_zero(pf, pad, c);
		// ft_memset(s, ' ', pad);
		// pf->fspec.buffer = strjoin_f(s, pf->fspec.buffer, 'B');
	}
	return (1);
}

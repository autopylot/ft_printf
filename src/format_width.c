/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:45:50 by wlin              #+#    #+#             */
/*   Updated: 2017/07/31 19:31:24 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pad_zero(t_printf *pf, int pad, char c)
{
	char	*s;
	int		i;

	s = ft_strnew(pad);
	ft_memset(s, c, pad);
	if (c == ' ')
		i = 0;
	else
		i = ((pf->fspec.buffer[0] == '-') ? 1 : 0);
	insert_substring(pf->fspec.buffer, s, i + 1);
	ft_strdel(&s);
}

void			format_width(t_printf *pf)
{
	char	c;
	int		pad;

	if (((pad = pf->fspec.width - ft_strlen(pf->fspec.buffer)) > 0))
	{
		c = ' ';
		if (pf->fspec.precision == -1 && !pf->fspec.left && pf->fspec.pad)
		{
			if (ft_strchr("dDiuoxXUO", pf->fspec.spec))
				c = '0';
		}
		pad_zero(pf, pad, c);
	}
}

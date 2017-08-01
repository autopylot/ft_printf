/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:45:50 by wlin              #+#    #+#             */
/*   Updated: 2017/08/01 14:25:57 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pad_zero(t_printf *pf, int pad, char c)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(ft_strlen(pf->fspec.buffer) + pad);
	if (c == '0' && *(pf->fspec.buffer) == '-')
	{
		s[i] = pf->fspec.buffer[i];
		++i;
	}
	ft_memset(s + i, c, pad);
	ft_strcpy(s + i + pad, pf->fspec.buffer + i);
	ft_strdel(&(pf->fspec.buffer));
	pf->fspec.buffer = s;
}

void			format_width(t_printf *pf)
{
	char	c;
	int		pad;

	if (!*(pf->fspec.buffer))
		return ;
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

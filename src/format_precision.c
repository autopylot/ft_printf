/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:01:56 by wlin              #+#    #+#             */
/*   Updated: 2017/08/01 11:19:47 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sig_num(char *buffer)
{
	int i;

	i = 0;
	while (*buffer)
	{
		if (ft_isalnum(*buffer))
			++i;
		++buffer;
	}
	return (i);
}

void		format_precision(t_printf *pf)
{
	int pad;

	if (ft_strchr("dDioOuUxX", pf->fspec.spec))
	{
		if (pf->fspec.precision == 0 && pf->fspec.buffer[0] == '0')
		{
			pf->fspec.buffer[0] = '\0';
			return ;
		}
		else if ((pad = pf->fspec.precision - sig_num(pf->fspec.buffer)) > 0)
			pad_zero(pf, pad, '0');
	}
	else if (pf->fspec.spec == 's')
	{
		if (pf->fspec.precision < (int)ft_strlen(pf->fspec.buffer))
			pf->fspec.buffer[pf->fspec.precision] = '\0';
	}
}

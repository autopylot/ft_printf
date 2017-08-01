/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 21:13:25 by wlin              #+#    #+#             */
/*   Updated: 2017/08/01 12:03:33 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	format_prefix2(t_printf *pf)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(pf->fspec.buffer);
	while (WS(pf->fspec.buffer[i]))
		++i;
	if (pf->fspec.precision == -1 && pf->fspec.buffer[i] == '0' && i >= 2)
	{
		ft_memcpy(pf->fspec.buffer + i, PREFIX(pf->fspec.spec), 2);
		return ;
	}
	else if (i >= 2)
	{
		ft_memcpy(pf->fspec.buffer + i - 2, PREFIX(pf->fspec.spec), 2);
		return ;
	}
	if (pf->fspec.precision == -1 && i == 1)
		ft_memmove(pf->fspec.buffer, pf->fspec.buffer + i, len);
	pf->fspec.buffer = strjoin_f(PREFIX(pf->fspec.spec), pf->fspec.buffer, 'R');
}

void			format_prefix(t_printf *pf)
{
	int i;

	i = 0;
	if (ft_strchr("oO", pf->fspec.spec) && pf->fspec.uints != 0)
	{
		while (WS(pf->fspec.buffer[i]))
			++i;
		if (pf->fspec.buffer[i] == '0')
			return ;
		else if (i != 0)
			pf->fspec.buffer[i - 1] = '0';
		else
			pf->fspec.buffer = strjoin_f("0", pf->fspec.buffer, 'R');
	}
	else if ((ft_strchr("xX", pf->fspec.spec) && pf->fspec.uints != 0))
		format_prefix2(pf);
}

void			format_space(t_printf *pf)
{
	if (!F_SINT(pf->fspec.spec))
		return ;
	if (pf->fspec.sints < 0 || pf->fspec.plus || pf->fspec.buffer[0] == ' ')
		return ;
	else if (pf->fspec.buffer[0] == '0' && pf->fspec.precision == -1)
		pf->fspec.buffer[0] = ' ';
	else if (pf->fspec.precision > -1 && pf->fspec.buffer[0] != ' ')
		pf->fspec.buffer = strjoin_f(" ", pf->fspec.buffer, 'R');
	else
		pf->fspec.buffer = strjoin_f(" ", pf->fspec.buffer, 'R');
}

void			format_plus(t_printf *pf)
{
	int i;

	i = 0;
	if (!F_SINT(pf->fspec.spec) || pf->fspec.sints < 0)
		return ;
	while (WS(pf->fspec.buffer[i]))
		++i;
	if (pf->fspec.precision > -1 && i > 0)
		pf->fspec.buffer[i - 1] = '+';
	else if (i > 0)
	{
		if (pf->fspec.buffer[i] == '0' && pf->fspec.width == 0)
			pf->fspec.buffer[i] = '+';
		else
			pf->fspec.buffer[i - 1] = '+';
	}
	else
		pf->fspec.buffer = strjoin_f("+", pf->fspec.buffer, 'R');
}

void			format_left(t_printf *pf)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(pf->fspec.buffer);
	while (WS(pf->fspec.buffer[i]))
		++i;
	if (pf->fspec.space)
		--i;
	if (i > 0)
	{
		ft_memmove(pf->fspec.buffer, pf->fspec.buffer + i, len - i);
		ft_memset(pf->fspec.buffer + len - i, ' ', i);
	}
}

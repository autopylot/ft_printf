/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 21:13:25 by wlin              #+#    #+#             */
/*   Updated: 2017/07/25 11:56:40 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void format_prefix(t_printf *pf)
{
	int i;

	i = 0;
	if (pf->fspec.spec == 'o' && pf->fspec.uints != 0)
	{
		while (WS(pf->fspec.buffer[i]))
			++i;
		if (pf->fspec.buffer[i] == '0')
			return (1);
		else if (i != 0)
			pf->fspec.buffer[i - 1] = '0';
		else
			pf->fspec.buffer = strjoin_f("0", pf->fspec.buffer, 'R');
		return (1);
	}
	else if (ft_strchr("xX", pf->fspec.spec) && pf->fspec.uints != 0)
	{
		while (WS(pf->fspec.buffer[i]))
			++i;
		if (pf->fspec.precision == -1 && pf->fspec.buffer[i + 1] == '0')
			ft_memcpy(pf->fspec.buffer + i, PREFIX(pf->fspec.spec), 2);
		else if (i >= 2)
			ft_memcpy(pf->fspec.buffer + i - 2, PREFIX(pf->fspec.spec), 2);
		else
		{
			if (pf->fspec.precision == -1 && i == 1)
				ft_memmove(pf->fspec.buffer, pf->fspec.buffer + i, ft_strlen(pf->fspec.buffer));
			pf->fspec.buffer = strjoin_f(PREFIX(pf->fspec.spec), pf->fspec.buffer, 'R');
		}
	}
}

void format_space(t_printf *pf)
{
	if (!F_SINT(pf->fspec.spec))
		return (0);
	if (pf->fspec.sints < 0 || pf->fspec.plus)
		return (1);
	else if (pf->fspec.buffer[0] == ' ')
		return (1);
	else if (pf->fspec.buffer[0] == '0' && pf->fspec.precision == -1)
		pf->fspec.buffer[0] = ' ';
	else if (pf->fspec.precision > -1 && pf->fspec.buffer[0] != ' ')
		pf->fspec.buffer = strjoin_f(" ", pf->fspec.buffer, 'R');
	else
		pf->fspec.buffer = strjoin_f(" ", pf->fspec.buffer, 'R');
	return (1);
}

int format_plus(t_printf *pf)
{
	int i;

	i = 0;
	if (!F_SINT(pf->fspec.spec))
		return (0);
	if (pf->fspec.sints < 0)
		return (1);
	while (WS(pf->fspec.buffer[i]))
		++i;
	if (pf->fspec.precision > -1 && i != 0)
		pf->fspec.buffer[i - 1] = '+';
	else if (pf->fspec.precision == -1 && pf->fspec.buffer[i] == '0')
	{
		if (pf->fspec.buffer[i] == '0')
			pf->fspec.buffer[i] = '+';
		else
			pf->fspec.buffer[i - 1] = '+';
	}
	else
		pf->fspec.buffer = strjoin_f("+", pf->fspec.buffer, 'R');
	return (1);
}

int format_left(t_printf *pf)
{
	int i;

	i = 0;
	while (WS(pf->fspec.buffer[i]))
		++i;
	if (pf->fspec.space)
		--i;
	if (i > 0)
	{
		ft_memmove(pf->fspec.buffer, pf->fspec.buffer + i, ft_strlen(pf->fspec.buffer) - i);
		ft_memset(pf->fspec.buffer + ft_strlen(pf->fspec.buffer) - i, ' ', i);
	}
	return (1);
}

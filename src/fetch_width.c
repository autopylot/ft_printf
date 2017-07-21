/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 20:45:50 by wlin              #+#    #+#             */
/*   Updated: 2017/07/20 14:48:33 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int fetch_width(t_printf *pf)
{
	int pad;

	if (((pad = pf->fspec.p_width - ft_strlen(pf->fspec.buffer)) > 0))
	{
		char *s = ft_strnew(pad);
		ft_memset(s, ' ', pad);
		pf->fspec.buffer = strjoin_f(s, pf->fspec.buffer, 'B');
	}
	return (1);
}


int format_prefix(t_printf *pf)
{
	int i;

	i = 0;
	if (pf->fspec.spec == 'o' && pf->fspec.uints != 0)
	{
		while (WS(pf->fspec.buffer[i]))
			++i;
		if (pf->fspec.buffer[i] == '0')
			return (1);
		else if (pf->fspec.buffer[i - 1] == ' ')
			pf->fspec.buffer[i - 1] = '0';
		else
			pf->fspec.buffer = strjoin_f("0", pf->fspec.buffer, 'R');
		return (1);
	}
	else if (pf->fspec.spec == 'x' && pf->fspec.uints != 0)
	{
		while (WS(pf->fspec.buffer[i]))
			++i;
		printf("i = %d\n", i);
		// if (pf->fspec.buffer[i - 2])
		// 	ft_memcpy(pf->fspec.buffer + i - 2, PREFIX(pf->fspec.spec), 2);
		 if (pf->fspec.precision == -1 && pf->fspec.buffer[i + 1] == '0')
			ft_memcpy(pf->fspec.buffer + i, PREFIX(pf->fspec.spec), 2);
		else if (pf->fspec.buffer[i - 2] == ' ')
			ft_memcpy(pf->fspec.buffer + i - 2, PREFIX(pf->fspec.spec), 2);
		else
		{
			if (pf->fspec.precision == -1 && pf->fspec.buffer[i + 1] != '0')
				ft_memmove(pf->fspec.buffer, pf->fspec.buffer + 1, ft_strlen(pf->fspec.buffer));
			pf->fspec.buffer = strjoin_f(PREFIX(pf->fspec.spec), pf->fspec.buffer, 'R');
		}
	}
	return (0);
}

int format_space(t_printf *pf)
{
	if (!F_SINT(pf->fspec.spec))
		return (0);
	if (pf->fspec.sints < 0 || !pf->fspec.space)
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
	printf("%s\n", pf->fspec.buffer);
	if (!F_SINT(pf->fspec.spec))
		return (0);
	if (pf->fspec.sints < 0)
		return (1);
	while (WS(pf->fspec.buffer[i]))
		++i;
	if (pf->fspec.precision > -1 && i != 0)
		pf->fspec.buffer[i - 1] = '+';
	else if (pf->fspec.precision == -1)
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



}

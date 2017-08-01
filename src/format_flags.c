/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 21:13:25 by wlin              #+#    #+#             */
/*   Updated: 2017/08/01 15:06:37 by wlin             ###   ########.fr       */
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
	if (i > 1)
	{
		ft_memcpy(pf->fspec.buffer + i - 2, PREFIX(pf->fspec.spec), 2);
		return ;
	}
	if (pf->fspec.precision == -1)
	{
		if (pf->fspec.buffer[i] == '0' && pf->fspec.buffer[i + 1] == '0')
		{
			ft_memcpy(pf->fspec.buffer + i, PREFIX(pf->fspec.spec), 2);
			return ;
		}
	}
	if (i == 1 || (pf->fspec.precision == -1 && pf->fspec.buffer[i] == '0'))
		ft_memmove(pf->fspec.buffer, pf->fspec.buffer + 1, len);
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
	if (i > 0)
		pf->fspec.buffer[i - 1] = '+';
	else if (i > 0 && pf->fspec.buffer[i] == '0' && pf->fspec.precision == -1)
			pf->fspec.buffer[i] = '+';
	else if (i > 0 && pf->fspec.buffer[i] != '0')
			pf->fspec.buffer[i - 1] = '+';
	else if (pf->fspec.sints == 0)
		pf->fspec.buffer = strjoin_f("+", pf->fspec.buffer, 'R');
	else if (pf->fspec.precision == -1 && pf->fspec.buffer[i] == '0')
		pf->fspec.buffer[i] = '+';
	else
		pf->fspec.buffer = strjoin_f("+", pf->fspec.buffer, 'R');
}

void			format_left(t_printf *pf)
{
	int		i;
	int		len;
	char	*s;
	char	*ptr;

	i = 0;
	ptr = pf->fspec.buffer;
	len = ft_strlen(pf->fspec.buffer);
	s = ft_strnew(len);
	while (WS(*ptr))
		++ptr;
	while(*ptr)
		s[i++] = *ptr++;
	while (i < len)
		s[i++] = ' ';
	ft_strdel(&(pf->fspec.buffer));
	pf->fspec.buffer = s;
	ft_strdel(&s);
}

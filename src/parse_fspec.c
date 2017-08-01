/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:41:47 by wlin              #+#    #+#             */
/*   Updated: 2017/08/01 14:36:06 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		parse_flag(t_fmt_spec *fspec, char flag)
{
	if (flag == '-')
		return (fspec->left = 1);
	else if (flag == '#')
		return (fspec->prefix = 1);
	else if (flag == '0')
		return (fspec->pad = 1);
	else if (flag == ' ')
		return (fspec->space = 1);
	else if (flag == '+')
		return (fspec->plus = 1);
	return (0);
}

static	int		parse_number(t_fmt_spec *fspec, char width)
{
	if (F_NUM(width))
	{
		if (!(fspec->precision < 0))
			return (fspec->precision = fspec->precision * 10 + (width - '0'));
		if (width == '.')
			return (!(fspec->precision = 0));
		return (fspec->width = fspec->width * 10 + (width - '0'));
	}
	return (-1);
}

static	int		parse_length(t_fmt_spec *fspec, char len)
{
	if (fspec->length == 0 && F_LEN(len))
	{
		if (len == 'h')
			return (fspec->length = 2);
		else if (len == 'l')
			return (fspec->length = 3);
		else if (len == 'z')
			return (fspec->length = 5);
		else if (len == 'j')
			return (fspec->length = 6);
	}
	else if ((fspec->length == 2 && len == 'h') ||
				(fspec->length == 3 && len == 'l'))
		return ((fspec->length = (len == 'h' ? 1 : 4)));
	return (0);
}

static	int		parse_spec(t_fmt_spec *fspec, char type)
{
	if (F_SPEC(type))
		return (fspec->spec = type);
	return (0);
}

int				parse_fspec(t_printf *pf, const char **fmt)
{
	if (*(*fmt) == '%')
		++(*fmt);
	if (*(*fmt) == '%')
	{
		ft_putchar(*(*fmt)++);
		++pf->len;
		return (1);
	}
	while (parse_flag(&(pf->fspec), *(*fmt)))
		++(*fmt);
	while ((parse_number(&(pf->fspec), *(*fmt))) > -1)
		++(*fmt);
	while (parse_length(&(pf->fspec), *(*fmt)))
		++(*fmt);
	if (!parse_spec(&(pf->fspec), *(*fmt)++))
		return (0);
	pdispatch(pf);
	//ft_strdel(&(pf->fspec.buffer));
	init(&(pf->fspec));
	return (1);
}

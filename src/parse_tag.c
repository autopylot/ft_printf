/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:41:47 by wlin              #+#    #+#             */
/*   Updated: 2017/07/12 11:51:44 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int parse_flag(t_fmt_tag *tag, char flag)
{
	if (flag == '-' && !tag->left)
		return (tag->left = 1);
	else if ((flag == '#') && (!tag->pre_zero))
		return (tag->pre_zero = 1);
	else if ((flag == '0') && (!tag->pad_zero))
		return(tag->pad_zero = 1);
	else if ((flag == ' ') && !tag->space)
		return (tag->space = 1);
	return (0);
}

static	int parse_number(t_fmt_tag *tag, char width)
{
	if ((width >= '0' && width <= '9') || width == '.')
	{
		if (!(tag->precision < 0))
			return(tag->precision = tag->precision * 10 + (width - '0'));
		if (width == '.')
			return(!(tag->precision = 0));
		else
			return (tag->p_width = tag->p_width * 10 + (width - '0'));
	}
	return (0);
}

static	int parse_length(t_fmt_tag *tag, char len)
{
	if (tag->length == none && ft_strchr(LEN, len))
		return (tag->length = len);
	else if (tag->length == len)
	{
		tag->length = (len == h ? hh : ll);
		return (1);
	}
	return (0);
}

static	int parse_spec(t_fmt_tag *tag, char type)
{
	char *sptr;

	if ((sptr = ft_strchr(SPEC, type)))
		return (tag->spec = type);
	return (0);
}

/*
	Parses format string for specs
*/
int	parse_tag(t_printf *ptbl)
{
	char *fmt;
	int i;

	i = 0;
	fmt = ptbl->fmt_string;
	while (*fmt)
	{
		if (*fmt++ == '%')
		{
			if (*fmt == '%')
			{
				++fmt;
				continue ;
			}
			while (parse_flag(&(ptbl->fmt_tbl[i]), *fmt))
				++fmt;
			while (parse_number(&(ptbl->fmt_tbl[i]), *fmt))
				++fmt;
			while (parse_length(&(ptbl->fmt_tbl[i]), *fmt))
				++fmt;
			if (parse_spec(&(ptbl->fmt_tbl[i]), *fmt))
				va_copy(ptbl->fmt_tbl[i++].arg, ptbl->ap);
			else
				return (0);
			++fmt;
		}
	}
	return (1);
}

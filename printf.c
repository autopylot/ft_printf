/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:30:39 by wlin              #+#    #+#             */
/*   Updated: 2017/07/10 16:44:38 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
	
*/
static	int	n_fmtspec(char *fmt_str)
{
	char	*fmtptr;
	int		n_specs;

	n_specs = 0;
	fmtptr = (char*)fmt_str;
	while (*fmtptr)
	{
		if (*fmtptr++ == '%')
		{
			if (*fmtptr == '%')
				++fmtptr;
			while (ft_strchr(FLAGS, *fmtptr))
			 	++fmtptr;
			while (ft_strchr(NUMBER, *fmtptr))
				++fmtptr;
			while (ft_strchr(LEN, *fmtptr))
				++fmtptr;
		 	if (ft_strchr(SPEC, *fmtptr))
					n_specs++;
		}
		else
			fmtptr++;
	}
	return (n_specs);
}

void init_fmt_tag(t_fmt_tag *tag)
{
	tag->left = 0;
	tag->pre_zero = 0;
	tag->pad_zero = 0;
	tag->p_width = 0;
	tag->precision = 0;
	tag->length = none;
	tag->spec = NULL;
	tag->len = 0;
	tag->fmt_buf = NULL;
}

void init_printf(t_printf *ptbl, char *fmt_str)
{
	int i;

	i = -1;
	(*ptbl).fmt_string = fmt_str;
	va_start((*ptbl).ap, fmt_str);
	(*ptbl).len = n_fmtspec(fmt_str);
	(*ptbl).fmt_tbl = (t_fmt_tag*)malloc(t_fmt_tag) * (len + 1);
	while (++i < len)
		init_fmt_tag(&((*ptbl).fmt_tbl[i]));
	(*ptbl).fmt_tbl[len + 1] = NULL;
}

/*
	Returns the total length of the output string
*/
int	ft_printf(const char *format,...)
{
	t_printf	ptbl;
	int ret_len;
	char *fmtptr;

	fmtptr = (char*)format;
	while (*fmtptr)
	{
		if (*fmtptr == '%')
		{

		}
	}
	va_start(arg, format);
	ret_len = va_dispatch();
	va_end(arg);
	return (done);
}

/*Parses format string for specs





*/
int	va_dispatch(char *format, va_list arg)
{
	char *fmt;


	fmt = format;
	while (*fmt != '\0')
	{
		if (*fmt == '%' && *(fmt + 1) == '%')

	}
}

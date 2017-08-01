/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:30:39 by wlin              #+#    #+#             */
/*   Updated: 2017/08/01 10:50:36 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_fmt_spec *fspec)
{
	fspec->left = 0;
	fspec->pad = 0;
	fspec->plus = 0;
	fspec->space = 0;
	fspec->prefix = 0;
	fspec->width = 0;
	fspec->precision = -1;
	fspec->length = 0;
	fspec->spec = ' ';
	fspec->sints = 0;
	fspec->uints = 0;
	fspec->buffer = NULL;
}

int		ft_printf(const char *format, ...)
{
	t_printf	pf;

	pf.len = 0;
	init(&(pf.fspec));
	va_start(pf.ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!parse_fspec(&pf, &format))
				return (-1);
		}
		else
		{
			ft_putchar(*format++);
			++pf.len;
		}
	}
	va_end(pf.ap);
	return (pf.len);
}

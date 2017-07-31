/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:30:39 by wlin              #+#    #+#             */
/*   Updated: 2017/07/29 21:31:58 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_format(t_printf *pf)
{
	printf("Left: %d\n", pf->fspec.left);
	printf("Prefix: %d\n", pf->fspec.prefix);
	printf("Plus: %d\n", pf->fspec.plus);
	printf("Pad zero: %d\n", pf->fspec.pad);
	printf("Space: %d\n", pf->fspec.space);
	printf("Width: %d\n", pf->fspec.width);
	printf("Precision: %d\n", pf->fspec.precision);
	printf("Length: %d\n", pf->fspec.length);
	printf("Spec tag: %c\n", pf->fspec.spec);
	printf("Buffer is: -%s-\n", pf->fspec.buffer);
}

void init(t_fmt_spec *fspec)
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

int	ft_printf(const char *format,...)
{
	t_printf	pf;

	if (!*format)
		return (0);
	pf.len = 0;
	init(&(pf.fspec));
	va_start(pf.ap, format);
	while (*format)
	{
		if (*format == '%')
			parse_fspec(&pf, &format);
		else
		{
			ft_putchar(*format++);
			++pf.len;
		}
	}
	va_end(pf.ap);
	return (pf.len);
}

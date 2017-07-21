/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:30:39 by wlin              #+#    #+#             */
/*   Updated: 2017/07/20 17:07:54 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_format(t_printf *pf)
{
	printf("Left: %d\n", pf->fspec.left);
	printf("Prefix: %d\n", pf->fspec.prefix);
	printf("Plus: %d\n", pf->fspec.plus);
	printf("Pad zero: %d\n", pf->fspec.pad_zero);
	printf("Space: %d\n", pf->fspec.space);
	printf("Width: %d\n", pf->fspec.p_width);
	printf("Precision: %d\n", pf->fspec.precision);
	printf("Length: %d\n", pf->fspec.length);
	printf("Spec tag: %c\n", pf->fspec.spec);
	printf("Buffer is: %s\n", pf->fspec.buffer);
}

static void init_pf(t_printf *pf, const char *format)
{
	pf->format = (char*)format;
	pf->buffer = NULL;
	pf->fspec.left = 0;
	pf->fspec.pad = 0;
	pf->fspec.plus = 0;
	pf->fspec.space = 0;
	pf->fspec.prefix = 0;
	pf->fspec.width = 0;
	pf->fspec.precision = -1;
	pf->fspec.length = 0;
	pf->fspec.spec = ' ';
	pf->fspec.sints = 0;
	pf->fspec.uints = 0;
	pf->fspec.buffer = NULL;
}

int	ft_printf(const char *format,...)
{
	t_printf	pf;
	int 		len;

	init_pf(&pf, format);
	va_start(pf.ap, format);
	while (*format)
	{
		if (*format == '%')
			parse_fspec(pf, &format);
		else
			pf->buffer =
	}
	if (parse_fspec(&pf))
	{
		print_format(&pf);
	}
	len = 0;
	va_end(pf.ap);
	return (len);
}

int main()
{
 	//char *c = "helloldkj dfgd dfg4dvc%";
	//int a = 1;
	ft_printf("Print this int: %+05d and this char: ", 1);
	return (0);
}

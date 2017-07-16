/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:30:39 by wlin              #+#    #+#             */
/*   Updated: 2017/07/14 15:00:18 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void print_tbl(t_printf *ptbl)
{
	int i = 0;
	puts(ptbl->fmt_string);
	printf("%d\n", ptbl->len);
	while (i < ptbl->len)
	{
		printf("Left adjust: %d\n", ptbl->fmt_tbl[i].left);
		printf("Pre zero: %d\n", ptbl->fmt_tbl[i].pre_zero);
		printf("Pad zero: %d\n", ptbl->fmt_tbl[i].pad_zero);
		printf("Space before pos: %d\n", ptbl->fmt_tbl[i].space);
		printf("Min width: %d\n", ptbl->fmt_tbl[i].p_width);
		printf("Precision: %d\n", ptbl->fmt_tbl[i].precision);
		printf("Length: %u\n", ptbl->fmt_tbl[i].length);
		printf("Spec tag: %c\n", ptbl->fmt_tbl[i].spec);
		i++;
	}
}

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

/*
	Initializes fmt tag struct
*/
void init_fmt_tag(t_fmt_tag *tag)
{
	tag->left = 0;
	tag->pre_zero = 0;
	tag->pad_zero = 0;
	tag->space = 0;
	tag->p_width = 0;
	tag->precision = -1;
	tag->length = none;
	tag->spec = ' ';
	tag->len = 0;
	tag->fmt_buf = NULL;
}

/*
	Initializes printf struct along with fmt_tbl array inside
*/
void init_printf(t_printf *ptbl, char *fmt_str)
{
	int i;

	i = -1;
	(*ptbl).fmt_string = fmt_str;
	(*ptbl).len = n_fmtspec(fmt_str);
	(*ptbl).fmt_tbl = (t_fmt_tag*)malloc(sizeof(t_fmt_tag) * ((*ptbl).len));
	while (++i < (*ptbl).len)
		init_fmt_tag(&((*ptbl).fmt_tbl[i]));
}

/*
	Returns the total length of the output string
*/
int	ft_printf(const char *format,...)
{
	t_printf	ptbl;
	int 		len;

	init_printf(&ptbl, (char*)format);
	va_start(ptbl.ap, format);
	if (parse_tag(&ptbl))
		print_tbl(&ptbl);
	//call parse
	//len = va_dispatch();
	len = 0;
	va_end(ptbl.ap);
	return (len);
}



int main()
{
	int x = 5;
	char c = 'A';

	ft_printf("Print this int: %-# 09.58lld and this char: ", x, c);
	return (0);
}

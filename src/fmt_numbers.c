/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:01:56 by wlin              #+#    #+#             */
/*   Updated: 2017/07/20 13:06:02 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

  char *substring(char *string, int position, int length)
{
  char *pointer;
  int c;

   c = -1;
  pointer = malloc(length+1);
  if( pointer == NULL )
	  exit(EXIT_FAILURE);
  while (++c < length)
	 *(pointer+c) = *((string+position-1)+c);
  *(pointer+c) = '\0';
  return pointer;
}

  void insert_substring(char *a, char *b, int position)
{
  char *f, *e;
  int length;

  length = ft_strlen(a);
  f = substring(a, 1, position - 1 );
  e = substring(a, position, length-position+1);
  ft_strcpy(a, "");
  ft_strcat(a, f);
  free(f);
  ft_strcat(a, b);
  ft_strcat(a, e);
  free(e);
}


int digit_len(int n)
{
	int len;

	printf("Digit len: %d\n", n);
	len = 0;
	if (n == 0)
		return (1);
	while (n && ++len)
		n /= 10;
	return (len);
}

int sig_digits(char *buffer)
{
	int i;

	i = 0;
	while (!(*buffer >= '1' && *buffer <= '9') && *buffer)
		++buffer;
	while ((*buffer >= '1' && *buffer <= '9') && *buffer)
	{
		++buffer;
		++i;
	}
	return (i);
}
int	pad_zero(t_printf *pf, int pad, char c)
{
	char *s;
	char *neg;
	int i;

	s = ft_strnew(pad);
	ft_memset(s, c, pad);
	i = ((pf->fspec.buffer[0] == '-') ? 1 : 0);
	insert_substring(pf->fspec.buffer, s, i + 1);
	ft_strdel(&s);
	return (1);
}


int fmt_precision(t_printf *pf)
{
	int pad;
	char *s;
	if (pf->fspec.precision == 0 && pf->fspec.buffer[0] == '0')
			pf->fspec.buffer[0] = '\0';
	else if (pf->fspec.spec == 'd' || pf->fspec.spec == 'i')
	{
		if (pf->fspec.precision <= digit_len(pf->fspec.sints))
			return (0);
		pad = pf->fspec.precision - digit_len(pf->fspec.sints);
		return (pad_zero(pf, pad, '0'));
	}
	else if ((ft_strchr("ouxX", pf->fspec.spec)))
	{
		printf("Precision: %d, digit len: %d\n", pf->fspec.precision, sig_digits(pf->fspec.buffer));
		if (pf->fspec.precision <= sig_digits(pf->fspec.buffer))
			return (0);
		pad = pf->fspec.precision - sig_digits(pf->fspec.buffer);
		return (pad_zero(pf, pad, '0'));
	}
	else if (pf->fspec.spec == 's')
	{
		if (pf->fspec.precision < ft_strlen(pf->fspec.buffer))
			pf->fspec.buffer[pf->fspec.precision] = '\0';
	}
	return (0);
}

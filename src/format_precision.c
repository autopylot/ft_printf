/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:01:56 by wlin              #+#    #+#             */
/*   Updated: 2017/07/31 12:19:44 by wlin             ###   ########.fr       */
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

// static int sig_num(char *buffer)
// {
// 	int i;
//
// 	i = 0;
// 	while (!(*buffer >= '1' && *buffer <= '9') && *buffer)
// 		++buffer;
// 	while ((*buffer >= '0' && *buffer <= '9') && *buffer)
// 	{
// 		++buffer;
// 		++i;
// 	}
// 	return (i);
// }

void format_precision(t_printf *pf)
{
	int pad;

	if (ft_strchr("dDioOuUxX", pf->fspec.spec))
	{
		if (pf->fspec.precision == 0 && pf->fspec.buffer[0] == '0')
		{
			pf->fspec.buffer[0] = '\0';
			return ;
		}
		else if ((pad = pf->fspec.precision - (int)ft_strlen(pf->fspec.buffer)) < 1)
			return ;
		pad_zero(pf, pad, '0');
	}
	else if (pf->fspec.spec == 's')
	{
		if (pf->fspec.precision < (int)ft_strlen(pf->fspec.buffer))
			pf->fspec.buffer[pf->fspec.precision] = '\0';
	}
}

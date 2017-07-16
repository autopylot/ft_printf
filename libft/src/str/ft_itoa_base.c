/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:25:29 by wlin              #+#    #+#             */
/*   Updated: 2017/07/15 19:25:31 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_base(int value, int base)
{
	char	*s;
	long	n;
	int		i;

	n = (value < 0) ? -(long)value : value;
	i = (value < 0) ? 2 : 1;
	while ((n /= base) >= 1)
		++i;
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	(value < 0) ? s[0] = '-' : 0;
	n = (value < 0) ? -(long)value : value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	return (s);
}

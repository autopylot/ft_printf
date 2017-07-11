/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:13:47 by wlin              #+#    #+#             */
/*   Updated: 2017/07/08 19:56:00 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_digits(int n)
{
	int			n_size;

	n_size = 1;
	if (n < 0)
	{
		n_size++;
		n = -n;
	}
	while (n /= 10)
		n_size++;
	return (n_size);
}

static	char		*ft_to_str(char *s)
{
	int			i;
	char		*ret;

	i = 0;
	ret = (char*)malloc(ft_strlen(s) + 1);
	while (i < (int)ft_strlen(s))
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char				*ft_itoa(int n)
{
	int			i;
	int			neg;
	char		*str;

	i = 0;
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	if (n == 0)
		return (ft_to_str("0"));
	else if (n == -2147483648 || n == 2147483647)
		return (n < 0 ? ft_to_str("-2147483648") : ft_to_str("2147483647"));
	else
	{
		if (!(str = ft_strnew((ft_digits(n) + 1))))
			return (NULL);
		while (n)
		{
			str[i++] = ((n % 10) > 9) ? ((n % 10) - 10) + 'a' : (n % 10) + '0';
			n /= 10;
		}
		(neg) ? str[i++] = '-' : i;
		str[i] = '\0';
		ft_strrev(str);
		return (str);
	}
}

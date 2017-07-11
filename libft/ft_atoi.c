/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:38:42 by wlin              #+#    #+#             */
/*   Updated: 2017/07/08 19:55:40 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ws(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int		num;
	int		sign;
	char	*str_ptr;

	num = 0;
	sign = 1;
	str_ptr = (char*)str;
	if (!*str_ptr || !str_ptr)
		return (0);
	while (ft_ws(*str_ptr))
		str_ptr++;
	if (*str_ptr == '-')
	{
		sign = -1;
		str_ptr++;
	}
	else if (*str_ptr == '+')
		str_ptr++;
	while (*str_ptr >= '0' && *str_ptr <= '9')
	{
		num = num * 10 + (*str_ptr - '0');
		str_ptr++;
	}
	return (num * sign);
}

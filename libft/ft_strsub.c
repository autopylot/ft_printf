/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:55:10 by wlin              #+#    #+#             */
/*   Updated: 2017/06/17 19:51:10 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	char	*sub_ptr;
	int		i;

	i = 0;
	if (s)
	{
		sub_str = (char*)malloc(sizeof(char) * (len + 1));
		sub_ptr = sub_str;
		if (sub_str)
		{
			while (len--)
			{
				*sub_ptr = *(s + start + i);
				sub_ptr++;
				i++;
			}
			*sub_ptr = '\0';
		}
		return (sub_str);
	}
	else
		return (NULL);
}

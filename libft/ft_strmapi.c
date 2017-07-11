/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:17:27 by wlin              #+#    #+#             */
/*   Updated: 2017/06/17 19:49:09 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map_str;
	char	*s_ptr;
	int		i;

	i = 0;
	s_ptr = (char*)s;
	if (s_ptr)
	{
		map_str = (char*)malloc(ft_strlen((char*)s) + 1);
		if (map_str)
		{
			while (*s_ptr != '\0')
			{
				map_str[i] = f(i, *s_ptr);
				i++;
				s_ptr++;
			}
		}
		else
			return (NULL);
		map_str[i] = '\0';
		return (map_str);
	}
	else
		return (NULL);
}

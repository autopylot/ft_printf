/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:47:33 by wlin              #+#    #+#             */
/*   Updated: 2017/06/17 19:43:37 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (*little == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] || little[j] == '\0')
		{
			if (little[j] == '\0')
			{
				return ((big + i + j <= big + (int)len) ?
				(char*)big + i : NULL);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

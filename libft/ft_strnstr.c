/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:47:33 by wlin              #+#    #+#             */
/*   Updated: 2017/07/15 11:20:32 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	n = ft_strlen(little);
	if (!*little)
		return ((char*)big);
	while (*big && (len-- >= n))
		if (ft_strncmp(big++, little, n) == 0)
			return ((char *)big++ - 1);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:37:43 by wlin              #+#    #+#             */
/*   Updated: 2017/07/08 20:17:09 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	i = 0;
	if (!*s1 && *s2 && i < n)
		return (-1 * (*s22));
	if (!*s2 && *s1 && i < n)
		return (*s11);
	while (*(s11 + i) && *(s22 + i) && i < n)
	{
		if (*(s11 + i) > *(s22 + i))
			return (*(s11 + i) - *(s22 + i));
		if (*(s11 + i) < *(s22 + i))
			return (*(s11 + i) - *(s22 + i));
		if (*(s11 + i) == *(s22 + i))
			i++;
		if (*(s11 + i) && !*(s22 + i) && i < n)
			return (*(s11 + i));
		if (*(s22 + i) && !*(s11 + i) && i < n)
			return (-1 * (*(s22 + i)));
	}
	return (0);
}

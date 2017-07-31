/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:18:18 by wlin              #+#    #+#             */
/*   Updated: 2017/07/31 10:32:49 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dup;

	if (s1 == NULL)
		return (NULL);
	len = (int)ft_strlen(s1);
	if (!(dup = ft_strnew(len)))
		return (NULL);
	dup[len] = '\0';
	while (--len > -1)
		dup[len] = s1[len];
	return (dup);
}

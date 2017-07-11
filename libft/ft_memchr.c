/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:43:54 by wlin              #+#    #+#             */
/*   Updated: 2017/06/14 12:39:12 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s_ptr;

	s_ptr = (unsigned char*)s;
	while (n--)
	{
		if (*s_ptr == (unsigned char)c)
			return (s_ptr);
		else
			s_ptr++;
	}
	return (NULL);
}

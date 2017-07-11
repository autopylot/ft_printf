/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:57:30 by wlin              #+#    #+#             */
/*   Updated: 2017/06/14 12:39:52 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1_ptr;
	unsigned char *s2_ptr;

	s1_ptr = (unsigned char*)s1;
	s2_ptr = (unsigned char*)s2;
	while (n--)
	{
		if (*s1_ptr == *s2_ptr)
		{
			s1_ptr++;
			s2_ptr++;
		}
		else
			return (*s1_ptr - *s2_ptr);
	}
	return (0);
}

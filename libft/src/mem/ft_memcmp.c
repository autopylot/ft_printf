/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:57:30 by wlin              #+#    #+#             */
/*   Updated: 2017/07/14 16:50:55 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	int				i;

	i = 0;
	s1_ptr = (unsigned char*)s1;
	s2_ptr = (unsigned char*)s2;
	while (n--)
	{
		if (s1_ptr[i] - s2_ptr[i] != 0)
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}

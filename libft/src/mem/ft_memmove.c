/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:35:18 by wlin              #+#    #+#             */
/*   Updated: 2017/06/15 13:22:56 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *dst_ptr;
	unsigned char *src_ptr;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	if (dst_ptr < src_ptr)
	{
		while (n--)
			*dst_ptr++ = *src_ptr++;
	}
	else
	{
		dst_ptr += n;
		src_ptr += n;
		while (n--)
			*--dst_ptr = *--src_ptr;
	}
	return (dst);
}

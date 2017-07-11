/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:19:22 by wlin              #+#    #+#             */
/*   Updated: 2017/06/16 20:40:09 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *dst_ptr;

	dst_ptr = dst;
	while (len > 0 && *src != '\0')
	{
		*dst_ptr++ = *src++;
		--len;
	}
	while (len > 0)
	{
		*dst_ptr++ = '\0';
		--len;
	}
	return (dst);
}

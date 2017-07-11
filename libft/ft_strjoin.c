/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:39:46 by wlin              #+#    #+#             */
/*   Updated: 2017/06/17 20:11:02 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_str;
	char	*join_ptr;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 && s2)
	{
		s1_len = ft_strlen((char*)s1);
		s2_len = ft_strlen((char*)s2);
		if (!(join_str = (char*)malloc(s1_len + s2_len + 1)))
			return (NULL);
		join_ptr = join_str;
		while (*s1 != '\0')
			*join_ptr++ = *s1++;
		while (*s2 != '\0')
			*join_ptr++ = *s2++;
		*join_ptr = '\0';
		return (join_str);
	}
	else
		return (NULL);
}

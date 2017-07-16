/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:55:10 by wlin              #+#    #+#             */
/*   Updated: 2017/07/15 16:42:27 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;

	if (!s || !(sub_str = ft_strnew(len)))
		return (NULL);
	ft_strncpy(sub_str, s + start, len);
	sub_str[len] = '\0';
	return (sub_str);
}

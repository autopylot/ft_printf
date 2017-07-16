/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:17:27 by wlin              #+#    #+#             */
/*   Updated: 2017/07/14 21:36:55 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	int		i;

	i = -1;
	if (!s || !(mapi = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		mapi[i] = f(i, s[i]);
	mapi[i] = '\0';
	return (mapi);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 12:06:26 by wlin              #+#    #+#             */
/*   Updated: 2017/07/19 12:26:17 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strjoin_f(char *s1, char *s2, char c)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	join = ft_strcpy(join, (char*)s1);
	join = ft_strcat(join, (char*)s2);
	if (c == 'L')
		ft_strdel(&s1);
	else if (c == 'R')
		ft_strdel(&s2);
	else if (c == 'B')
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (join);
}

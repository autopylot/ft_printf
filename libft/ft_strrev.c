/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:54:36 by wlin              #+#    #+#             */
/*   Updated: 2017/07/14 10:51:47 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *s)
{
	int		start;
	int		end;
	char	temp;

	start = -1;
	end = ft_strlen(s);
	while (++start < --end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
	}
}

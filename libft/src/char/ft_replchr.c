/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:13:00 by wlin              #+#    #+#             */
/*   Updated: 2017/06/14 19:15:57 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replchr(char *str, char c1, char c2)
{
	char *pos;

	while ((pos = ft_strchr(str, c1)))
		*pos = c2;
}
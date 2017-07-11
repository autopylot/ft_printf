/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:01:48 by wlin              #+#    #+#             */
/*   Updated: 2017/06/14 19:11:08 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remchr(char *str, char c)
{
	char *str_ptr;

	while ((str_ptr = ft_strchr(str, c)))
		ft_memmove(str_ptr, str_ptr + 1, ft_strlen(str_ptr));
}

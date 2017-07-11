/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:04:09 by wlin              #+#    #+#             */
/*   Updated: 2017/06/17 10:58:33 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_lst;

	if (!(new_lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_lst->content = ft_memalloc(content_size + 1);
	new_lst->content_size = 0;
	new_lst->next = NULL;
	if (content)
		ft_memcpy(new_lst->content, content, content_size);
	else
		new_lst->content = NULL;
	return (new_lst);
}

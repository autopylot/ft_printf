/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 19:07:29 by wlin              #+#    #+#             */
/*   Updated: 2017/07/06 14:58:42 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *current;

	current = *alst;
	if (del)
	{
		while (current != NULL)
		{
			next = current->next;
			del(current->content, current->content_size);
			free(current);
			current = next;
		}
		*alst = NULL;
	}
}

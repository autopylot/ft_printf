/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:57:39 by wlin              #+#    #+#             */
/*   Updated: 2017/06/17 21:28:00 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *head)
{
	t_list *temp;

	temp = head;
	while (temp != NULL)
	{
		ft_putstr(head->content);
		ft_putchar('\n');
		temp = temp->next;
	}
}

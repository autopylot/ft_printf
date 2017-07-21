/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 18:50:45 by wlin              #+#    #+#             */
/*   Updated: 2017/07/14 20:47:26 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == (-2147483647 - 1))
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putstr_fd("147483648", fd);
		return ;
	}
	else if (n < 0)
		ft_putchar_fd('-', fd);
	n = ABS(n);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

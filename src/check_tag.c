/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 11:30:50 by wlin              #+#    #+#             */
/*   Updated: 2017/07/12 11:50:28 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Validate the format string
		Check correct order of tags
		check corect number of tags
*/
int check_fmt(const char *fmt)
{
	int flags;
	int length;

	flags = 0;
	length = 0;
	while (*fmt)
	{
		if (*fmt++ == '%')
		{
			if (*fmt == '%')
			{
				++fmt;
				continue ;
			}
			while (ft_strchr(FLAGS, *fmt) && flags < 4)
				++flags;
			while (ft_strchr(NUMBER, *fmt))
				++fmt;
			while (ft_strchr(LEN, *fmt) && length < 2)
				++fmt;
				++length;
		}
	}
}







/*
	Validate combination of tags and specifiers
*/

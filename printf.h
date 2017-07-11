/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:19:24 by wlin              #+#    #+#             */
/*   Updated: 2017/07/10 12:47:36 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRINTF_H
# define PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

#define FLAGS	("-+ #0")
#define NUMBER	(".0123456789")
#define LEN 	("hljz")
#define SPEC	("sSpdDioOuUxXcC")


typedef enum e_fmt_len
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
}	t_fmt_len;

typedef struct	s_fmt_tag
{
	int			left;
	int			pre_zero;
	int			pad_zero;
	int			p_width;
	int 		precision;
	t_fmt_len	length;
	//va_list		arg;
	char		spec;
	int			len;
	char		*fmt_buf;
}				t_fmt_tag;

typedef struct	s_printf
{
	char		*fmt_string;
	va_list		ap;
	int			len;
	t_fmt_tag	*fmt_tbl;
}				t_printf;

#endif

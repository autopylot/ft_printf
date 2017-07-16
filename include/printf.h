/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:19:24 by wlin              #+#    #+#             */
/*   Updated: 2017/07/15 20:49:31 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRINTF_H
# define PRINTF_H

# include "../libft/include/libft.h"

#define FLAGS	("-+ #0")
#define NUMBER	(".0123456789")
#define LEN 	("hljz")
#define SPEC	("sSpdDioOuUxXcC")


typedef enum  	e_fmt_len
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_fmt_len;

typedef struct	s_fmt_tag
{
	int			left;
	int			pre_zero;
	int			pad_zero;
	int 		space;
	int			p_width;
	int 		precision;
	t_fmt_len	length;
	char		spec;
	va_list		arg;
	int			len;
	char		*fmt_buf;
}				t_fmt_tag;

typedef struct	s_printf
{
	char		*fmt_string;
	char		*fmt_buf;
	va_list		ap;
	int			len;
	t_fmt_tag	*fmt_tbl;
}				t_printf;

int	parse_tag(t_printf *ptbl);

#endif

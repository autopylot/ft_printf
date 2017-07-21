/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:19:24 by wlin              #+#    #+#             */
/*   Updated: 2017/07/16 20:35:11 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

#define FLAGS	("-+ #0")
#define NUMBER	(".0123456789")
#define LEN 	("hljz")
#define SPEC	("sSpdDioOuUxXcC")
#define INTS	("di")
#define UINTS	("uoxX")

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

typedef union u_fetch
{
	int i;
	unsigned int ui;
	char *str;
	signed char sc;
	unsigned char usc;
	short s;
	unsigned short us;
	long l;
	unsigned long ul;
	long long ll;
	unsigned long long ull;
	intmax_t ixt;
	uintmax_t uixt;
	size_t	size;

}	t_fetch;

typedef struct	s_fmt_spec
{
	int			left;
	int			pre_zero;
	int			pad_zero;
	int 		space;
	int			p_width;
	int 		precision;
	t_fmt_len	length;
	char		spec;
	t_fetch		f;
	char		*buffer;
}				t_fmt_spec;

typedef struct	s_printf
{
	char		*format;
	char		*buffer;
	va_list		ap;
	t_fmt_spec	fspec;
}				t_printf;


int		parse_tag(t_printf *ptbl);
int		ft_printf(const char *format,...);


/*
**	libft functions
*/



#endif

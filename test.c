#include "printf.h"
#include "stdarg.h"

static	int	n_fmtspec(char *fmt_str)
{
	char	*fmtptr;
	int		n_specs;

	n_specs = 0;
	fmtptr = (char*)fmt_str;
	while (*fmtptr)
	{
		if (*fmtptr++ == '%')
		{
			if (*fmtptr == '%')
				++fmtptr;
			while (ft_strchr(FLAGS, *fmtptr))
			 	++fmtptr;
			while (ft_strchr(NUMBER, *fmtptr))
				++fmtptr;
			while (ft_strchr(LEN, *fmtptr))
				++fmtptr;
		 	if (ft_strchr(SPEC, *fmtptr))
			{
				++fmtptr;
				n_specs++;
			}
		}
		else
			fmtptr++;
	}
	return (n_specs);
}

void init_fmt_tag(t_fmt_tag *tag)
{
	tag->left = 0;
	tag->pre_zero = 0;
	tag->pad_zero = 0;
	tag->p_width = 0;
	tag->precision = 0;
	tag->length = none;
	tag->spec = ' ';
	tag->len = 0;
	tag->fmt_buf = NULL;
}

void init_printf(t_printf *ptbl, char *fmt_str)
{
	int i;

	i = -1;
	(*ptbl).fmt_string = fmt_str;
	//va_start((*ptbl).ap, fmt_str);
	(*ptbl).len = n_fmtspec(fmt_str);
	(*ptbl).fmt_tbl = (t_fmt_tag*)malloc(sizeof(t_fmt_tag) * ((*ptbl).len));
	while (++i < (*ptbl).len)
		init_fmt_tag(&((*ptbl).fmt_tbl[i]));
}

int	ft_printf(const char *format)
{
	t_printf	ptbl;

	init_printf(&ptbl, (char*)format);
	printf("%d\n", ptbl.len);
	printf("%d\n", ptbl.fmt_tbl[1].precision);
	return (0);
}

int main()
{
	ft_printf("This is the format string: first spec %09d then se %c ond %c this is the third %-8.9ld the fourth %d ");
	return (0);
}

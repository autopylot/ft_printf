/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 09:05:36 by wlin              #+#    #+#             */
/*   Updated: 2017/07/29 10:53:58 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define WS(c) (c == ' ' || c == '\t' || c == '\n' || ISSPACE2(c))
# define ISSPACE2(c) (c == '\r' || c == '\v' || c == '\f')
# define ABS(x) ((x) < 0 ? -(x) : (x))
# define MALLEN(x) (strlen(x) + 1)
# define LIM(x) ((x <= 2147483647 && x >= -2147483648) ? 1 : 0)

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memalloc(size_t size);
void 			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			*strjoin_f(char *s1, char *s2, char c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbelfki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:14:24 by zbelfki           #+#    #+#             */
/*   Updated: 2026/05/26 11:14:30 by zbelfki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_sizes(char *s, struct s_flgs *f, int *ss, int *ps)
{
	if (pf_strlen(s) < f->precision)
		*ss = pf_strlen(s);
	else
		*ss = f->precision;
	if (f->width > *ss)
		*ps = f->width - *ss;
	else
		*ps = 0;
}

int	pf_putstr_prewid(char *s, struct s_flgs *flags)
{
	int		ssize;
	int		padsize;
	int		i;
	char	c;

	c = ' ';
	if (flags->zero == 1 && flags->minus == 0)
		c = '0';
	get_sizes(s, flags, &ssize, &padsize);
	i = 0;
	while (flags->minus == 1 && i < flags->precision && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	i = 0;
	while (i++ < padsize)
		buf_write(flags->buffer, c, &flags->index);
	i = 0;
	while (flags->minus == 0 && i < flags->precision && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	if (ssize > flags->width)
		return (ssize);
	return (flags->width);
}

int	pf_putstr_wid(char *s, struct s_flgs *flags)
{
	int		padsize;
	int		i;
	char	c;

	c = ' ';
	if (flags->zero == 1 && flags->minus == 0)
		c = '0';
	if (flags->width > pf_strlen(s))
		padsize = flags->width - pf_strlen(s);
	else
		padsize = 0;
	i = 0;
	while (flags->minus == 1 && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	i = 0;
	while (i++ < padsize)
		buf_write(flags->buffer, c, &flags->index);
	i = 0;
	while (flags->minus == 0 && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	if (pf_strlen(s) > flags->width)
		return (pf_strlen(s));
	return (flags->width);
}

int	pf_putstr_pre(struct s_flgs *flags, char *s, int prec)
{
	int	ssize;
	int	i;

	if (pf_strlen(s) < prec)
		ssize = pf_strlen(s);
	else
		ssize = prec;
	i = 0;
	while (i < ssize && s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	return (ssize);
}

int	pf_putstr(struct s_flgs *flags, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		buf_write(flags->buffer, s[i++], &flags->index);
	return (i);
}

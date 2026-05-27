/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_du.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbelfki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:14:24 by zbelfki           #+#    #+#             */
/*   Updated: 2026/05/26 11:14:30 by zbelfki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_count(long n, struct s_flgs *flags)
{
	int	count;

	count = flags->precision - pf_nbrlen(n);
	count += (n < 0);
	if (count < 0)
		count = 0;
	return (count);
}

int	pf_putnbr_prewid(long n, struct s_flgs *flags)
{
	int	printed;
	int	count;
	int	padding;

	printed = 0;
	count = get_count(n, flags);
	padding = flags->width - pf_nbrlen(n) - count;
	if (padding < 0)
		padding = 0;
	printed += padding + count + pf_nbrlen(n);
	while (flags->minus == 0 && padding-- > 0)
		buf_write(flags->buffer, ' ', &flags->index);
	if (n < 0)
	{
		buf_write(flags->buffer, '-', &flags->index);
		n = -n;
	}
	while (count-- > 0)
		buf_write(flags->buffer, '0', &flags->index);
	pf_putnbr(flags, n);
	while (flags->minus == 1 && padding-- > 0)
		buf_write(flags->buffer, ' ', &flags->index);
	return (printed);
}

int	pf_putnbr_wid(long n, struct s_flgs *flags)
{
	int	printed;
	int	padding;

	printed = 0;
	padding = flags->width - pf_nbrlen(n);
	while (flags->minus == 0 && padding-- > 0)
	{
		buf_write(flags->buffer, ' ', &flags->index);
		printed++;
	}
	printed += pf_putnbr(flags, n);
	while (flags->minus == 1 && padding-- > 0)
	{
		buf_write(flags->buffer, ' ', &flags->index);
		printed++;
	}
	return (printed);
}

int	pf_putnbr_pre(long n, struct s_flgs *flags)
{
	int	printed;
	int	count;

	printed = 0;
	count = flags->width;
	if (flags->dot == 1)
		count = flags->precision;
	count -= pf_nbrlen(n);
	if (n < 0 && flags->dot == 1)
		count++;
	if (n < 0)
	{
		buf_write(flags->buffer, '-', &flags->index);
		n = -n;
		printed++;
	}
	while (count-- > 0)
	{
		buf_write(flags->buffer, '0', &flags->index);
		printed++;
	}
	printed += pf_putnbr(flags, n);
	return (printed);
}

int	pf_putnbr(struct s_flgs *flags, long n)
{
	char	c;
	int		printed;

	printed = 0;
	if (n < 0)
	{
		buf_write(flags->buffer, '-', &flags->index);
		printed++;
		n = -n;
	}
	if (n / 10 > 0)
		printed += pf_putnbr(flags, n / 10);
	c = n % 10 + '0';
	buf_write(flags->buffer, c, &flags->index);
	printed++;
	return (printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbelfki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:14:24 by zbelfki           #+#    #+#             */
/*   Updated: 2026/05/26 11:14:30 by zbelfki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_nbrlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	pf_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	buf_write(char *buffer, char c, int *printed)
{
	buffer[*printed % 4096] = c;
	(*printed)++;
	if (*printed % 4096 == 0 && *printed)
	{
		write(1, buffer, 4096);
	}
}

int	func_branch(const char *s, int *i, va_list args, struct s_flgs *flags)
{
	(*i)++;
	flagger(s, i, flags, args);
	if (s[*i] == 'c')
		pf_print_char(va_arg(args, int), flags);
	else if (s[*i] == 's')
		pf_print_str(va_arg(args, char *), flags);
	else if (s[*i] == 'p')
		pf_print_mem(va_arg(args, unsigned long), flags);
	else if (s[*i] == 'd' || s[*i] == 'i')
		pf_print_nbr(va_arg(args, int), flags);
	else if (s[*i] == 'u')
		pf_print_nbr(va_arg(args, unsigned int), flags);
	else if (s[*i] == 'x' || s[*i] == 'X')
		pf_print_hex(va_arg(args, unsigned int), flags, s[*i]);
	else if (s[*i] == 'o')
		pf_print_oct(va_arg(args, unsigned int), flags);
	else
		pf_print_other(s[*i], flags);
	if (s[*i] != '\0')
		(*i)++;
	return (1);
}

int	ft_printf(const char *string, ...)
{
	va_list			args;
	int				i;
	struct s_flgs	flags;

	va_start(args, string);
	i = 0;
	flags.index = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			func_branch(string, &i, args, &flags);
		else
			buf_write(flags.buffer, string[i++], &flags.index);
	}
	va_end(args);
	write(1, flags.buffer, flags.index % 4096);
	return (flags.index);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:55:17 by egjika            #+#    #+#             */
/*   Updated: 2025/09/09 20:55:17 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_format(char c, va_list list)
{
	int	count = 0;

	if (c == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (c == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(list, unsigned int));
	else if (c == 'p')
		count += ft_putptr(va_arg(list, void *));
	else if (c == 'x')
		count += ft_puthex(va_arg(list, unsigned int));
	else if (c == 'X')
		count += ft_puthexa(va_arg(list, unsigned int));
	else if (c == '%')
		count += ft_putchar('%');
	return(count);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	lentotal;
	va_list list;

	i = 0;
	lentotal = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			lentotal += ft_format(format[i + 1], list);
			i++;
		}
		else
			lentotal += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (lentotal);
}

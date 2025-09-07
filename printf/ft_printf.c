/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:55:20 by marvin            #+#    #+#             */
/*   Updated: 2025/09/06 19:55:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_format(char c, va_list list)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (c == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (c == 'd')
		count += ft_putnbr(va_arg(list, int));
	else if (c =='i')
		count += ft_putnbr(va_arg(list, int));
	else if
		count += ft_putnbr_unsigned(va_arg(list, int));
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

int main()
{
	int c = ft_printf("tonzinc %d et le nombre de caracteres est de : ", 32);
	ft_printf("%d", c);
	return (0);
}

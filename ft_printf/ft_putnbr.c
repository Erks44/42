/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:54:32 by egjika            #+#    #+#             */
/*   Updated: 2025/09/09 20:54:32 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int a)
{
	int	compt;

	compt = 0;
	if (a < 0)
	{
		compt++;
		ft_putchar('-');
		if (a == -2147483648)
		{
			compt += ft_putchar('2');
			a = 147483648;
		}
		else
			a = -a;
	}
	if (a >= 10)
		compt += ft_putnbr(a / 10);
	compt += ft_putchar((a % 10) + '0');
	return (compt);
}

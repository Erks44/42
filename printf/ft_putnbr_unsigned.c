/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:54:07 by egjika            #+#    #+#             */
/*   Updated: 2025/09/09 20:54:07 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_unsigned(unsigned int a)
{
	int	len;

	len = 0;
	if (a >= 10)
		len += ft_putnbr_unsigned(a / 10);
	len += ft_putchar('0' + (a % 10));
	return (len);
}

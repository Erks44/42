/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:05:51 by egjika            #+#    #+#             */
/*   Updated: 2025/09/09 21:05:51 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long a)
{
	int	compt;

	compt = 0;
	if (a >= 16)
	{
		compt += ft_puthex(a / 16);
	}
	write(1, &"0123456789abcdef"[a % 16], 1);
	compt++;
	return (compt);
}

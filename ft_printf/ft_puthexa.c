/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:01:39 by egjika            #+#    #+#             */
/*   Updated: 2025/09/10 00:01:39 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long a)
{
	int	compt;

	compt = 0;
	if (a >= 16)
	{
		compt += ft_puthexa(a / 16);
	}
	write(1, &"0123456789ABCDEF"[a % 16], 1);
	compt++;
	return (compt);
}

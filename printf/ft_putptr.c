/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ putptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:31:50 by egjika            #+#    #+#             */
/*   Updated: 2025/09/10 00:31:50 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putptr(void *ptr)
{
	int	compt;
	unsigned long	adr;

	compt = 0;
	adr = (unsigned long)ptr;
	write(1, "0x", 2);
	compt += 2;
	compt += ft_puthex(adr);
	return (compt);
}

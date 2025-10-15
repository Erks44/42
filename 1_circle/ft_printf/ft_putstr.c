/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:55:31 by egjika            #+#    #+#             */
/*   Updated: 2025/09/09 20:55:31 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int len;

	len = 0;
	if (str == NULL)
		str = "(null)";
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
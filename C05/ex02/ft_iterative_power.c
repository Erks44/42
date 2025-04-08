/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:14:17 by egjika            #+#    #+#             */
/*   Updated: 2025/04/02 11:21:27 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	else
	{
		while (1 < power)
		{
			result *= nb;
			power--;
		}
	}
	return (result);
}

/*int	main(void)
{
	int	n = 5;
	int	p = 5;
	printf("%d\n", ft_iterative_power(n, p));
	return(0);
}*/
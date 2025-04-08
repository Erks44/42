/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:50:06 by egjika            #+#    #+#             */
/*   Updated: 2025/04/02 11:18:51 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	else if (power > 1)
	{
		result *= ft_recursive_power(nb, power - 1);
	}
	return (result);
}

/*int	main(void)
{
	int	n = -5;
	int	p = 2;
	printf("%d\n", ft_recursive_power(n, p));
	return(0);
}*/
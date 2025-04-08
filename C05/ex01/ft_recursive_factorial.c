/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:09:33 by egjika            #+#    #+#             */
/*   Updated: 2025/04/02 09:30:36 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	else
	{
		result = nb * ft_recursive_factorial(nb - 1);
	}
	return (result);
}

/*int	main(void)
{
	int	s = -7;
	
	printf("%d\n", ft_recursive_factorial(s));
}*/
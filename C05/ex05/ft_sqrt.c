/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:04:51 by egjika            #+#    #+#             */
/*   Updated: 2025/04/07 14:35:18 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	low;
	int	max;
	int	i;

	low = 1;
	max = nb;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	if (nb > 46340 * 46340)
		max = 46340;
	while (low <= max)
	{
		i = (low + max) / 2;
		if (i * i == nb)
			return (i);
		else if (i * i < nb)
			low = i + 1;
		else
			max = i - 1;
	}
	return (0);
}

/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <number>\n", argv[0]);
		return (1);
	}

	int nb = atoi(argv[1]);
	int result = ft_sqrt(nb);

	printf("ft_sqrt(%d) = %d\n", nb, result);
	return (0);
}*/
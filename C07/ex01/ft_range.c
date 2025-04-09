/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:27:48 by egjika            #+#    #+#             */
/*   Updated: 2025/04/09 10:35:24 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*val;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	val = malloc((max - min) * sizeof(int));
	if (val == NULL)
		return (0);
	while (min < max)
	{
		val[i] = min;
		min++;
		i++;
	}
	return (val);
}

/*int	main()
{
	int	c = 0;
	int	min = -10;
	int	max = -5;
	int *test = ft_range(min, max);
	if (test == NULL)
		return (1);
	while (c < (max - min))
	{
		printf("%d ", test[c]);
		c++;
	}
	free(test);
	return (0);
}*/
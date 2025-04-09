/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:19:19 by egjika            #+#    #+#             */
/*   Updated: 2025/04/09 11:53:26 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range,int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return(0);
	}
	*range = malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);	
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
}

/*int	main()
{
	int	*tab;
	int	min = 5;
	int	max = 11;
	printf("%d",ft_ultimate_range(&tab, min, max));
	free(tab);
}*/

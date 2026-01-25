/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:57:50 by egjika            #+#    #+#             */
/*   Updated: 2025/06/27 17:04:05 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;
	size_t			i;

	if (num && size > SIZE_MAX / num)
	{
		return (NULL);
	}
	total_size = num * size;
	ptr = malloc(total_size);
	if (!ptr)
	{
		return (NULL);
	}
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

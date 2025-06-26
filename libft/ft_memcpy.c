/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:03:11 by marvin            #+#    #+#             */
/*   Updated: 2025/06/24 16:04:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			i;
	unsigned char	*srce;
	unsigned char	*dest;

	srce = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dest[i] = srce[i];
		i++;
	}
	return (dst);
}

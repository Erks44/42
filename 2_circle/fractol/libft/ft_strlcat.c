/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:31:46 by egjika            #+#    #+#             */
/*   Updated: 2025/06/27 18:31:52 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	len_d = 0;
	len_s = 0;
	while (dst[len_d] && len_d < dstsize)
		len_d++;
	while (src[len_s])
		len_s++;
	if (dstsize <= len_d)
		return (dstsize + len_s);
	while (src[i] && len_d + i < dstsize - 1)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_s + len_d);
}

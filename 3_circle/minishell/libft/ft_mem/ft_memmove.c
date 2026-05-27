/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbelfki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:14:24 by zbelfki           #+#    #+#             */
/*   Updated: 2026/05/26 11:14:30 by zbelfki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	*q;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	p = (unsigned char *)dst;
	q = (unsigned char *)src;
	i = 0;
	if (p > q)
	{
		while (len-- > 0)
			p[len] = q[len];
	}
	else
	{
		while (i < len)
		{
			p[i] = q[i];
			i++;
		}
	}
	return (dst);
}

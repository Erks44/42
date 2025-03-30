/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:28:18 by marvin            #+#    #+#             */
/*   Updated: 2025/03/30 16:54:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	y;

	i = 0;
	y = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[y] != '\0')
	{
		dest[i] = src[y];
		y++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	amg[50] = "Ton";
	char	*cls = "zinc";
	printf ("%s\n", ft_strcat(amg, cls));
	return (0);
}*/
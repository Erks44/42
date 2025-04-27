/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:23:21 by marvin            #+#    #+#             */
/*   Updated: 2025/04/02 14:44:41 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[y])
		{
			y++;
			if (to_find[y] == '\0')
			{
				return (&str[i - y + 1]);
			}
		}
		else
		{
			y = 0;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char *amg = "Helloguysfhdhdfthfudfsyh";
	char *bit = "goy";
	printf("%s\n", ft_strstr(amg, bit));
	return (0);
}
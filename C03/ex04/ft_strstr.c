/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:23:21 by marvin            #+#    #+#             */
/*   Updated: 2025/03/30 20:59:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char *ft_strstr(char *str, char *to_find)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (to_find[0] == '\0') 
	{
		return (str);
	}	
	while(str[i])
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
	return (NULL);
}

/*int	main(void)
{
	char *amg = "tufaiqfdsfaisuoi";
	char *bit = "tonzinc";
	printf("%s\n", ft_strstr(amg, bit));
	return (0);
}*/
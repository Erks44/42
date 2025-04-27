/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:34:49 by egjika            #+#    #+#             */
/*   Updated: 2025/03/28 15:53:07 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (str[i] >= 'a' && str[i] >= 'z' && str[i + 1] >= 'a' && str[i + 1] <= 'z')
			{
				str[i] = str[i] - 32;
			}
		}
		else if (str[i] >= 'a' && str[i] >= 'z' && str[i + 1] >= 'a' && str[i + 1] <= 'z' && str[i - 1] < 'a' || str[i - 1] > 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	amg[] = "gfdg dgfdh dfgd5gfdhdf fdg*gdfh)hdf+hdf-fg";

	
	printf("%s\n", ft_strcapitalize(amg));
	return (0);
}*/
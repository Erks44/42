/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:53:49 by egjika            #+#    #+#             */
/*   Updated: 2025/03/28 14:53:20 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] < 0 || str[i] > 31) && (str[i] != 127)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int	main(void)
{
	char *cls = "tonzinc";
	char *cls1 = "Hello\nWorld";  // Contient '\n' (ASCII 10)
	char *cls2 = "Tab\tTest";     // Contient '\t' (ASCII 9)
	char *cls3 = "Bell\aSound";   // Contient '\a' (ASCII 7)
	char *cls4 = "\x1F";          // ASCII 31 (non imprimable)
	char *cls5 = "DEL\x7F";       // ASCII 127 (DEL)
	printf("%d\n", ft_str_is_printable(cls));
	printf("%d\n", ft_str_is_printable(cls1));
	printf("%d\n", ft_str_is_printable(cls2));
	printf("%d\n", ft_str_is_printable(cls3));
	printf("%d\n", ft_str_is_printable(cls4));
	printf("%d\n", ft_str_is_printable(cls5));
	return (0);
}*/
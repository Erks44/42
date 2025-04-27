/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:17:23 by egjika            #+#    #+#             */
/*   Updated: 2025/04/09 22:29:11 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	char *s;
	while(src[i])
		i++;
	s = malloc(i + 1);
	i = 0;
	while(src[i])
	{
		s[i] = src[i];
		i++;
	}
	return(s);
}

/*#include <stdio.h>

int main()
{
	printf("%s", ft_strdup("tonzinc"));
	return 0;
}*/
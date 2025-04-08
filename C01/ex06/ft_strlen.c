/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:15:14 by egjika            #+#    #+#             */
/*   Updated: 2025/03/25 15:15:19 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_strlen(char *str)
{
	int	compt;

	compt = 0;
	while (str[compt])
	{
		compt++;
	}
	return (compt);
}
/*
int	main(void)
{
	char	*mot = "FortyTwo";
	int	r = ft_strlen(mot);
	printf("Le nb de caractères est de : %d\n", r);
	return (0);
}
*/
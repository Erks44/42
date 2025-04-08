/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:59:41 by egjika            #+#    #+#             */
/*   Updated: 2025/03/24 15:59:45 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int	main(void)
{
	int	a = 10;
	int	b = 3;
	int	div;
	int	mod;
	ft_div_mod(a, b, &div, &mod);
	printf(" Division : %d\n", div);
	printf(" Reste : %d\n", mod);
}*/
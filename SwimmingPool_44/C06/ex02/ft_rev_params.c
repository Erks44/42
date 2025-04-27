/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:42:43 by egjika            #+#    #+#             */
/*   Updated: 2025/04/08 13:12:24 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	y;

	y = argc - 1;
	while (y > 0)
	{
		i = 0;
		while (argv[y][i])
			i++;
		write(1, argv[y], i);
		write(1, "\n", 1);
		y--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:18:52 by egjika            #+#    #+#             */
/*   Updated: 2025/04/08 13:27:29 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	y;

	y = 1;
	while (argc > y)
	{
		i = 0;
		while (argv[y][i])
			i++;
		write(1, argv[y], i);
		write(1, "\n", 1);
		y++;
	}
	return (0);
}

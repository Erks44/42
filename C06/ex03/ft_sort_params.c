/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:06:42 by egjika            #+#    #+#             */
/*   Updated: 2025/04/08 15:10:12 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0'))
		return (s1[i] - s2[i]);
	return (0);
}

void	ft_sort_param(char **tab, int argc)
{
	int		i;
	int		y;
	char	*temp;

	i = 1;
	while (i < argc - 1)
	{
		y = i + 1;
		while (y < argc)
		{
			if (ft_strcmp(tab[y], tab[i]) < 0)
			{
				temp = tab[y];
				tab[y] = tab[i];
				tab[i] = temp;
			}
			y++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	y;

	ft_sort_param(argv, argc);
	i = 1;
	while (i < argc)
	{
		y = 0;
		while (argv[i][y])
			y++;
		write(1, argv[i], y);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

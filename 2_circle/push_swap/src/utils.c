/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:25:19 by egjika            #+#    #+#             */
/*   Updated: 2026/01/12 17:13:41 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_fail(t_stack *a)
{
	if (a && a->v)
		free(a->v);
	if (a)
	{
		a->v = NULL;
		a->size = 0;
		a->cap = 0;
	}
	ps_error();
}

void	ps_free_split(char **t)
{
	int	i;

	if (!t)
		return ;
	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}

int	ps_count_split(char **t)
{
	int	i;

	i = 0;
	while (t && t[i])
		i++;
	return (i);
}

void	ps_check_duplicates(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->v[i] == a->v[j])
				ps_fail(a);
			j++;
		}
		i++;
	}
}

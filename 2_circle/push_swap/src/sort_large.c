/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:56:13 by ylanamonros       #+#    #+#             */
/*   Updated: 2026/01/12 17:03:06 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_find_min_index(t_stack *a)
{
	int	i;
	int	min_index;

	min_index = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->v[i] < a->v[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

static void	ps_bring_min_to_top(t_stack *a, int min_index)
{
	while (min_index != 0)
	{
		if (min_index <= a->size / 2)
		{
			ps_ra(a);
			min_index--;
		}
		else
		{
			ps_rra(a);
			min_index++;
			if (min_index == a->size)
				min_index = 0;
		}
	}
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_index;

	while (a->size > 3)
	{
		min_index = ps_find_min_index(a);
		ps_bring_min_to_top(a, min_index);
		ps_pb(a, b);
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_small(a, b);
	while (b->size > 0)
		ps_pa(a, b);
}

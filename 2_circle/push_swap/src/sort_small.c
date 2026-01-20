/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:22:01 by ylanamonros       #+#    #+#             */
/*   Updated: 2026/01/13 18:58:46 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->v[0] > a->v[1])
		ps_sa(a);
}

void	sort_three(t_stack *a)
{
	if (a->size != 3)
		return ;
	if (a->v[0] > a->v[1] && a->v[1] < a->v[2] && a->v[0] < a->v[2])
		ps_sa(a);
	else if (a->v[0] > a->v[1] && a->v[1] > a->v[2])
	{
		ps_sa(a);
		ps_rra(a);
	}
	else if (a->v[0] > a->v[1] && a->v[1] < a->v[2] && a->v[0] > a->v[2])
		ps_ra(a);
	else if (a->v[0] < a->v[1] && a->v[1] > a->v[2] && a->v[0] < a->v[2])
	{
		ps_sa(a);
		ps_ra(a);
	}
	else if (a->v[0] < a->v[1] && a->v[1] > a->v[2] && a->v[0] > a->v[2])
		ps_rra(a);
}

static int	ps_find_min_index(t_stack *a)
{
	int	i;
	int	min_index;

	i = 0;
	min_index = 0;
	while (i < a->size)
	{
		if (a->v[i] < a->v[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

static void	ps_push_min_to_b(t_stack *a, t_stack *b)
{
	int	index;
	int	r;

	index = ps_find_min_index(a);
	if (index <= a->size / 2)
	{
		r = index;
		while (r-- > 0)
			ps_ra(a);
	}
	else
	{
		r = a->size - index;
		while (r-- > 0)
			ps_rra(a);
	}
	ps_pb(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
	{
		ps_push_min_to_b(a, b);
		sort_three(a);
		ps_pa(a, b);
	}
	else if (a->size == 5)
	{
		ps_push_min_to_b(a, b);
		ps_push_min_to_b(a, b);
		sort_three(a);
		ps_pa(a, b);
		ps_pa(a, b);
	}
}

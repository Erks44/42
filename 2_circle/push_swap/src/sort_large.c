/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylanamonrose <ylanamonrose@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:56:13 by ylanamonros       #+#    #+#             */
/*   Updated: 2026/01/11 16:41:02 by ylanamonros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_index;
	int	i;

	while (a->size > 3)
	{
		min_index = 0;
		i = 1;
		while (i < a->size)
		{
			if (a->v[i] < a->v[min_index])
				min_index = i;
			i++;
		}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylanamonrose <ylanamonrose@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:24:52 by ylanamonros       #+#    #+#             */
/*   Updated: 2026/01/11 11:36:36 by ylanamonros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pb(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	if (a->size == 0)
		return ;
	tmp = a->v[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->v[i] = a->v[i + 1];
		i++;
	}
	a->size--;
	i = b->size;
	while (i > 0)
	{
		b->v[i] = b->v[i - 1];
		i--;
	}
	b->v[0] = tmp;
	b->size++;
	write(1, "pb\n", 3);
}

void	ps_pa(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	if (b->size == 0)
		return ;
	tmp = b->v[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->v[i] = b->v[i + 1];
		i++;
	}
	b->size--;
	i = a->size;
	while (i > 0)
	{
		a->v[i] = a->v[i - 1];
		i--;
	}
	a->v[0] = tmp;
	a->size++;
	write(1, "pa\n", 3);
}
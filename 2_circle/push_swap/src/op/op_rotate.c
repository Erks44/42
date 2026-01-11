/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylanamonrose <ylanamonrose@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:45:16 by ylanamonros       #+#    #+#             */
/*   Updated: 2026/01/11 16:50:42 by ylanamonros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_stack *a)
{
	int tmp;
	int i;

	i = 0;
	if (a->size < 2)
		return ;
	tmp = a->v[0];
	while (i < a->size - 1)
	{
		a->v[i] = a->v[i + 1];
		i++;
	}
	a->v[a->size - 1] = tmp;
	write(1, "ra\n", 3);
}

void	ps_rb(t_stack *b)
{
	int tmp;
	int i;

	i = 0;
	if (b->size < 2)
		return ;
	tmp = b->v[0];
	while (i < b->size - 1)
	{
		b->v[i] = b->v[i + 1];
		i++;
	}
	b->v[b->size - 1] = tmp;
	write(1, "rb\n", 3);
}

void	ps_rr(t_stack *a, t_stack *b)
{
	int tmp;
	int i;

	if (a->size >= 2)
	{
		i = 0;
		tmp = a->v[0];
		while (i < a->size - 1)
		{
			a->v[i] = a->v[i + 1];
			i++;
		}
		a->v[a->size - 1] = tmp;
	}
	if (b->size >= 2)
	{
		i = 0;
		tmp = b->v[0];
		while (i < b->size - 1)
		{
			b->v[i] = b->v[i + 1];
			i++;
		}
		b->v[b->size - 1] = tmp;
	}
	write(1, "rr\n", 3);
}

void	ps_rra(t_stack *a)
{
	int tmp;
	int i;

	i = a->size - 1;
	if (a->size < 2)
		return ;
	tmp = a->v[a->size - 1];
	while (i > 0)
	{
		a->v[i] = a->v[i - 1];
		i--;
	}
	a->v[0] = tmp;
	write(1, "rra\n", 4);
}

void	ps_rrb(t_stack *b)
{
	int tmp;
	int i;

	i = b->size - 1;
	if (b->size < 2)
		return ;
	tmp = b->v[b->size - 1];
	while (i > 0)
	{
		b->v[i] = b->v[i - 1];
		i--;
	}
	b->v[0] = tmp;
	write(1, "rrb\n", 4);
}

void	ps_rrr(t_stack *a, t_stack *b)
{
	int tmp;
	int i;

	if (a->size >= 2)
	{
		i = a->size - 1;
		tmp = a->v[a->size - 1];
		while (i > 0)
		{
			a->v[i] = a->v[i - 1];
			i--;
		}
		a->v[0] = tmp;
	}
	if(b->size >= 2)
	{
		i = b->size - 1;
		tmp = b->v[b->size - 1];
		while (i > 0)
		{
			b->v[i] = b->v[i - 1];
			i--;
		}
		b->v[0] = tmp;
	}
	write(1, "rrr\n", 4);
}


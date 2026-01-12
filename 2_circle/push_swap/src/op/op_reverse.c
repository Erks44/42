/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:00:54 by egjika            #+#    #+#             */
/*   Updated: 2026/01/12 17:12:54 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ps_reverse_no_write(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size < 2)
		return ;
	i = s->size - 1;
	tmp = s->v[s->size - 1];
	while (i > 0)
	{
		s->v[i] = s->v[i - 1];
		i--;
	}
	s->v[0] = tmp;
}

void	ps_rra(t_stack *a)
{
	ps_reverse_no_write(a);
	write(1, "rra\n", 4);
}

void	ps_rrb(t_stack *b)
{
	ps_reverse_no_write(b);
	write(1, "rrb\n", 4);
}

void	ps_rrr(t_stack *a, t_stack *b)
{
	ps_reverse_no_write(a);
	ps_reverse_no_write(b);
	write(1, "rrr\n", 4);
}

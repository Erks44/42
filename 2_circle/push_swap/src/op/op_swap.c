/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:33:31 by ylanamonros       #+#    #+#             */
/*   Updated: 2026/01/11 10:33:31 by ylanamonros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ps_sa(t_stack *a)
{
	int tmp;

	if (a->size < 2)
		return;
	tmp = a->v[0];
	a->v[0] = a->v[1];
	a->v[1] = tmp;
	write(1, "sa\n", 3);
}

void	ps_sb(t_stack *b)
{
	int tmp;

	if (b->size < 2)
		return;
	tmp = b->v[0];
	b->v[0] = b->v[1];
	b->v[1] = tmp;
	write(1, "sb\n", 3);
}

void ps_ss(t_stack *a, t_stack *b)
{
    int tmp;

    if (a->size >= 2)
    {
        tmp = a->v[0];
        a->v[0] = a->v[1];
        a->v[1] = tmp;
    }

    if (b->size >= 2)
    {
        tmp = b->v[0];
        b->v[0] = b->v[1];
        b->v[1] = tmp;
    }

    write(1, "ss\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:06:27 by egjika            #+#    #+#             */
/*   Updated: 2026/01/12 20:22:41 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_init_stacks(t_stack *a, t_stack *b)
{
	a->v = NULL;
	a->size = 0;
	a->cap = 0;
	b->v = NULL;
	b->size = 0;
	b->cap = 0;
}

static void	ps_alloc_b_or_exit(t_stack *a, t_stack *b)
{
	b->v = (int *)malloc(sizeof(int) * (size_t)a->cap);
	if (!b->v)
	{
		free(a->v);
		ps_error();
	}
	b->cap = a->cap;
	b->size = 0;
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	ps_init_stacks(&a, &b);
	ps_parse(&a, ac, av);
	if (ps_is_sorted(&a))
	{
		free(a.v);
		return (0);
	}
	ps_alloc_b_or_exit(&a, &b);
	if (a.size <= 5)
		sort_small(&a, &b);
	else
		sort_large(&a, &b);
	free(b.v);
	free(a.v);
	return (0);
}

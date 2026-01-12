/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:25:19 by egjika            #+#    #+#             */
/*   Updated: 2026/01/12 19:59:25 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_fill_values(t_stack *a, char **src, int offset)
{
	int	i;
	int	val;

	i = 0;
	while (i < a->size)
	{
		if (!ps_atoi_safe(src[i + offset], &val))
		{
			if (offset == 0)
				ps_free_split(src);
			ps_fail(a);
		}
		a->v[i] = val;
		i++;
	}
}

void	ps_parse_two_args(t_stack *a, char **argv)
{
	char	**t;

	t = ft_split(argv[1], ' ');
	if (!t)
		ps_error();
	a->size = ps_count_split(t);
	a->cap = a->size;
	if (a->size == 0)
		return (ps_free_split(t));
	a->v = (int *)malloc(sizeof(int) * (size_t)a->cap);
	if (!a->v)
	{
		ps_free_split(t);
		ps_error();
	}
	ps_fill_values(a, t, 0);
	ps_free_split(t);
	ps_check_duplicates(a);
}

int	ps_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ps_check_overflow(long res, long limit, int digit)
{
	if (res > (limit - digit) / 10)
		return (1);
	return (0);
}

long	ps_get_sign(const char *s, int *i)
{
	long	sign;

	sign = 1;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

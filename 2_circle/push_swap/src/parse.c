/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:25:19 by egjika            #+#    #+#             */
/*   Updated: 2026/01/12 20:22:35 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_accumulate_digits(const char *s, int *i, long limit, long *res)
{
	int	digit;

	*res = 0;
	while (ps_is_digit(s[*i]))
	{
		digit = s[*i] - '0';
		if (ps_check_overflow(*res, limit, digit))
			return (0);
		*res = *res * 10 + digit;
		(*i)++;
	}
	return (1);
}

int	ps_atoi_safe(const char *s, int *out)
{
	long	sign;
	long	res;
	long	limit;
	int		i;

	if (!s || !out)
		return (0);
	i = 0;
	sign = ps_get_sign(s, &i);
	if (!ps_is_digit(s[i]))
		return (0);
	limit = (long)INT_MAX + (sign == -1);
	if (!ps_accumulate_digits(s, &i, limit, &res))
		return (0);
	if (s[i] != '\0')
		return (0);
	*out = (int)(sign * res);
	return (1);
}

void	ps_parse(t_stack *a, int argc, char **argv)
{
	if (!a)
		ps_error();
	a->v = NULL;
	a->size = 0;
	a->cap = 0;
	if (argc < 2)
		return ;
	if (argc == 2)
		return (ps_parse_two_args(a, argv));
	a->size = argc - 1;
	a->cap = a->size;
	a->v = (int *)malloc(sizeof(int) * (size_t)a->cap);
	if (!a->v)
		ps_error();
	ps_fill_values(a, argv, 1);
	ps_check_duplicates(a);
}

int	ps_is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	if (a->size < 2)
		return (1);
	while (i < a->size - 1)
	{
		if (a->v[i] > a->v[i + 1])
			return (0);
		i++;
	}
	return (1);
}

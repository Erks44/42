/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylanamonrose <ylanamonrose@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:25:19 by egjika            #+#    #+#             */
/*   Updated: 2026/01/11 16:31:30 by ylanamonros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ps_atoi_safe(const char *s, int *out)
{
	long	sign;
	long	res;
	long	limit;
	int		i;
	int		digit;

	if (!s || !out)
		return (0);
	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!ps_is_digit(s[i]))
		return (0);
	res = 0;
	limit = (long)INT_MAX + (sign == -1);
	while (ps_is_digit(s[i]))
	{
		digit = s[i++] - '0';
		if (res > (limit - digit) / 10)
			return (0);
		res = res * 10 + digit;
	}
	if (s[i] != '\0')
		return (0);
	*out = (int)(sign * res);
	return (1);
}

static void	ps_fail(t_stack *a)
{
	if (a && a->v)
		free(a->v);
	if (a)
	{
		a->v = NULL;
		a->size = 0;
		a->cap = 0;
	}
	ps_error();
}

static void	ps_free_split(char **t)
{
	int	i;

	if (!t)
		return ;
	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}

static int	ps_count_split(char **t)
{
	int	i;

	i = 0;
	while (t && t[i])
		i++;
	return (i);
}

static void	ps_check_duplicates(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->v[i] == a->v[j])
				ps_fail(a);
			j++;
		}
		i++;
	}
}

static void	ps_fill_from_argv(t_stack *a, char **argv)
{
	int	i;
	int	val;

	i = 0;
	while (i < a->size)
	{
		if (!ps_atoi_safe(argv[i + 1], &val))
			ps_fail(a);
		a->v[i] = val;
		i++;
	}
}

static void	ps_fill_from_split(t_stack *a, char **t)
{
	int	i;
	int	val;

	i = 0;
	while (i < a->size)
	{
		if (!ps_atoi_safe(t[i], &val))
		{
			ps_free_split(t);
			ps_fail(a);
		}
		a->v[i] = val;
		i++;
	}
}

static void	ps_parse_two_args(t_stack *a, char **argv)
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
	ps_fill_from_split(a, t);
	ps_free_split(t);
	ps_check_duplicates(a);
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
	ps_fill_from_argv(a, argv);
	ps_check_duplicates(a);
}

int	ps_is_sorted(t_stack *a)
{
	int i;

	i = 0;
	if (a->size < 2)
		return (1);
	while(i < a->size - 1)
	{
		if(a->v[i] > a->v[i + 1])
			return (0);
		i++;
	}
	return (1);
}
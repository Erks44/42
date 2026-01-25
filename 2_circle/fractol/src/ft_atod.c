/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:49:07 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/25 13:15:59 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	skip_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	while (s[*i] == ' ' || s[*i] == '\t')
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	parse_int(const char *s, int *i, double *res)
{
	int	has_digit;

	has_digit = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		has_digit = 1;
		*res = *res * 10.0 + (s[*i] - '0');
		(*i)++;
	}
	return (has_digit);
}

static int	parse_frac(const char *s, int *i, double *res)
{
	double	f;
	int		has_digit;

	f = 0.1;
	has_digit = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		has_digit = 1;
		*res += (s[*i] - '0') * f;
		f *= 0.1;
		(*i)++;
	}
	return (has_digit);
}

int	ft_atod(const char *s, double *out)
{
	int		i;
	int		sign;
	int		has_digit;
	double	res;

	i = 0;
	res = 0.0;
	sign = skip_sign(s, &i);
	has_digit = parse_int(s, &i, &res);
	if (s[i] == '.')
	{
		i++;
		if (parse_frac(s, &i, &res))
			has_digit = 1;
	}
	if (!has_digit || s[i] != '\0')
		return (0);
	*out = res * sign;
	return (1);
}

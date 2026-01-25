/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 01:25:13 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/23 16:57:26 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	parse_args(t_fractol *f, int ac, char **av)
{
	if (ac == 2 && strcmp(av[1], "mandelbrot") == 0)
	{
		f->fractal_type = MANDELBROT;
	}
	else if (ac == 4 && strcmp(av[1], "julia") == 0)
	{
		f->fractal_type = JULIA;
		if (!ft_atod(av[2], &f->julia_c.re) || !ft_atod(av[3], &f->julia_c.im))
			print_usage();
	}
	else
		print_usage();
}

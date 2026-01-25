/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 01:24:00 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/25 13:24:59 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;

	ft_bzero(&f, sizeof(t_fractol));
	parse_args(&f, ac, av);
	init_defaults(&f);
	init_mlx(&f);
	mlx_mouse_hook(f.win, handle_mouse, &f);
	if (f.fractal_type == MANDELBROT)
		render_mandelbrot(&f);
	else if (f.fractal_type == JULIA)
		render_julia(&f);
	mlx_key_hook(f.win, handle_key, &f);
	mlx_hook(f.win, 17, 0, handle_close, &f);
	mlx_loop(f.mlx);
	return (0);
}

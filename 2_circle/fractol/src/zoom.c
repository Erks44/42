/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:23:30 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/25 13:34:04 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	render_current(t_fractol *f)
{
	if (f->fractal_type == MANDELBROT)
		render_mandelbrot(f);
	else
		render_julia(f);
}

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	t_complex	before;
	t_complex	after;
	double		factor;

	if (button == 4 || button == 1)
		factor = 1.2;
	else if (button == 5 || button == 2)
		factor = 1.0 / 1.2;
	else
		return (0);
	pixel_to_complex(f, x, y, &before);
	f->zoom *= factor;
	pixel_to_complex(f, x, y, &after);
	f->offset_x += before.re - after.re;
	f->offset_y += before.im - after.im;
	render_current(f);
	return (0);
}

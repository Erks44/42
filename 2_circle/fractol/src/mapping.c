/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:32:43 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/25 13:39:56 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_to_complex(t_fractol *f, int x, int y, t_complex *z)
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;

	if (f->fractal_type == MANDELBROT)
	{
		min_re = -2.0;
		max_re = 1.0;
		min_im = -1.5;
		max_im = 1.5;
	}
	else
	{
		min_re = -2.0;
		max_re = 2.0;
		min_im = -2.0;
		max_im = 2.0;
	}
	z->re = (min_re + (x / (double)(f->width - 1)) * (max_re - min_re))
		/ f->zoom + f->offset_x;
	z->im = (max_im - (y / (double)(f->height - 1)) * (max_im - min_im))
		/ f->zoom + f->offset_y;
}

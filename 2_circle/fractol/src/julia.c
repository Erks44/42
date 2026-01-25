/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:27:19 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/25 13:22:30 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_iter(t_fractol *f, t_complex z)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < f->max_iter && (z.re * z.re + z.im * z.im) <= 4.0)
	{
		tmp = z.re * z.re - z.im * z.im + f->julia_c.re;
		z.im = 2.0 * z.re * z.im + f->julia_c.im;
		z.re = tmp;
		i++;
	}
	return (i);
}

void	render_julia(t_fractol *f)
{
	int			x;
	int			y;
	int			iter;
	t_complex	z;
	int			color;

	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			pixel_to_complex(f, x, y, &z);
			iter = julia_iter(f, z);
			color = get_color(iter, f->max_iter);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

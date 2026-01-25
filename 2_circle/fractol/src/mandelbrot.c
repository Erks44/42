/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:56:03 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/25 13:22:37 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	mandelbrot_iter(t_fractol *f, t_complex c)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	z_re = 0.0;
	z_im = 0.0;
	i = 0;
	while (i < f->max_iter && (z_re * z_re + z_im * z_im) <= 4.0)
	{
		tmp = z_re * z_re - z_im * z_im + c.re;
		z_im = 2.0 * z_re * z_im + c.im;
		z_re = tmp;
		i++;
	}
	return (i);
}

void	render_mandelbrot(t_fractol *f)
{
	int			x;
	int			y;
	int			iter;
	t_complex	c;
	int			color;

	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			pixel_to_complex(f, x, y, &c);
			iter = mandelbrot_iter(f, c);
			color = get_color(iter, f->max_iter);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

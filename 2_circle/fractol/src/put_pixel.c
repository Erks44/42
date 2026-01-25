/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:14:13 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/23 17:35:46 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	put_pixel(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= f->width || y < 0 || y >= f->height)
		return ;
	dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

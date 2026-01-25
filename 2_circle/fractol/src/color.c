/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:03:45 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/25 13:06:33 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_color(int iter, int max_iter)
{
	int	t;
	int	r;
	int	g;
	int	b;

	if (iter >= max_iter)
		return (0x000000);
	t = (iter * 255) / max_iter;
	r = (t * 9) % 256;
	g = (t * 7) % 256;
	b = (t * 5) % 256;
	return ((r << 16) | (g << 8) | b);
}

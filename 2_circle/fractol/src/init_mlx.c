/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:11:33 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/23 17:12:52 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_mlx(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit(1);
	f->win = mlx_new_window(f->mlx, f->width, f->height, "fractol");
	if (!f->win)
		exit(1);
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	if (!f->img)
		exit(1);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	if (!f->addr)
		exit(1);
}

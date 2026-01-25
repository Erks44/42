/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:54:57 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/25 13:02:28 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	clean_exit(t_fractol *f, int code)
{
	if (!f)
		exit(code);
	if (f->mlx && f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->mlx && f->win)
		mlx_destroy_window(f->mlx, f->win);
	exit(code);
}

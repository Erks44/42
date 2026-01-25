/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_defaults.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:01:15 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/25 13:15:17 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_defaults(t_fractol *f)
{
	f->width = 800;
	f->height = 800;
	f->max_iter = 100;
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
}

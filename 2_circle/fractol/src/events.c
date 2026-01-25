/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 11:19:22 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/25 13:46:37 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_key(int keycode, t_fractol *f)
{
	if (keycode == 53 || keycode == 65307)
		clean_exit(f, 0);
	return (0);
}

int	handle_close(t_fractol *f)
{
	clean_exit(f, 0);
	return (0);
}

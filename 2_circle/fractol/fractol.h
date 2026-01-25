/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 01:20:21 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/01/25 13:33:08 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef enum e_fractal
{
	MANDELBROT,
	JULIA
}	t_fractal;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
	int			max_iter;

	double		zoom;
	double		offset_x;
	double		offset_y;

	int			fractal_type;
	t_complex	julia_c;
}	t_fractol;

void	print_usage(void);
void	parse_args(t_fractol *f, int ac, char **av);
int		ft_atod(const char *str, double *out);
void	init_defaults(t_fractol *f);
void	init_mlx(t_fractol *f);
void	put_pixel(t_fractol *f, int x, int y, int color);
void	render_mandelbrot(t_fractol *f);
int		handle_key(int keycode, t_fractol *f);
int		handle_close(t_fractol *f);
void	render_julia(t_fractol *f);
int		clean_exit(t_fractol *f, int code);
int		get_color(int iter, int max_iter);
int		handle_mouse(int button, int x, int y, t_fractol *f);
void	pixel_to_complex(t_fractol *f, int x, int y, t_complex *z);

#endif

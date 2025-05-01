/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:05:02 by miricci           #+#    #+#             */
/*   Updated: 2025/05/01 14:31:33 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_julia(t_fractal *fractal, char *re, char *im)
{
	if (!check_float(re) || !check_float(im))
		invalid_params(fractal, ERROR_TEXT);
	fractal->name = ft_strdup("julia");
	fractal->cx = ft_atof(re);
	fractal->cy = ft_atof(im);
}

void	parse_input(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			fractal->name = ft_strdup("mandelbrot");
		else if (!ft_strncmp(argv[1], "julia", 5))
			set_julia(fractal, "-0.5251993", "-0.5251993");
		else if (!ft_strncmp(argv[1], "burning ship", 12))
			fractal->name = ft_strdup("burning ship");
		else
			invalid_params(fractal, ERROR_TEXT);
	}
	else if (argc == 4)
	{
		if (!ft_strncmp(argv[1], "julia", 5))
			set_julia(fractal, argv[2], argv[3]);
		else
			invalid_params(fractal, ERROR_TEXT);
	}
	else
		invalid_params(fractal, ERROR_TEXT);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->zx = 0;
	fractal->zy = 0;
	fractal->zoom = 100;
	fractal->color = COLOR0;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->max_iteration = MAX_ITER;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		exit(1);
	fractal->mlx_window = mlx_new_window(fractal->mlx_ptr,
			WID, LEN, "Fract-ol");
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WID, LEN);
	fractal->img_addr = mlx_get_data_addr(fractal->img_ptr,
			&fractal->bits_per_pixel, &fractal->line_len, &fractal->endian);
}

void	init_hooks(t_fractal *fractal)
{
	mlx_mouse_hook(fractal->mlx_window, on_mouse_scroll, fractal);
	mlx_key_hook(fractal->mlx_window, on_keypress, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify,
		NoEventMask, close_display, fractal);
}

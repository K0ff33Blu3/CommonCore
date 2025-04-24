/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:05:02 by miricci           #+#    #+#             */
/*   Updated: 2025/04/24 15:30:57 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->zoom = 100;
	fractal->color = 0xd36582;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->max_iteration = 45;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		exit(1);
	fractal->mlx_window = mlx_new_window(fractal->mlx_ptr, WID, LEN, "Fract-ol");
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WID, LEN);
	fractal->img_addr = mlx_get_data_addr(fractal->img_ptr,
		&fractal->bits_per_pixel, &fractal->line_len, &fractal->endian);
}
void	init_hooks(t_fractal *fractal)
{
	mlx_mouse_hook(fractal->mlx_window, on_mouse_scroll, fractal);
	mlx_key_hook(fractal->mlx_window, on_keypress, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, NoEventMask, close_display, fractal);
}
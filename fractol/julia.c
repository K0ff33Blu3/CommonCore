/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:43:46 by miricci           #+#    #+#             */
/*   Updated: 2025/04/24 16:23:38 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractal *fractal)
{
	int	i;
	double x_tmp;
	double zx;
	double zy;

	i = 0;
	zx = ((fractal->x - LEN / 2.0) / fractal->zoom) + fractal->offset_x;
	zy = ((fractal->y - WID / 2.0) / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iteration)
	{
		x_tmp = zx * zx - zy * zy + fractal->cx;
		zy = 2 * zx * zy + fractal->cy;
		zx = x_tmp;
		if (zx * zx + zy * zy >= 4.0)
			break ;
	}
	if (i == fractal->max_iteration)
		putpixels(fractal, fractal->x, fractal->y, 0x000000);
	else
		putpixels(fractal, fractal->x, fractal->y, fractal->color * i);
}

void	put_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->y < LEN)
	{
		while (fractal->x < WID)
		{
			julia(fractal);
			fractal->x++;
		}
		fractal->x = 0;
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->mlx_window, fractal->img_ptr, 0, 0);
}
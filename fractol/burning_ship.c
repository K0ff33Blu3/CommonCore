/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:29:22 by miricci           #+#    #+#             */
/*   Updated: 2025/05/01 13:48:22 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_abs(double nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static void	calc_burning_ship(t_fractal *fractal)
{
	double	zx_abs;
	double	zy_abs;
	double	x_tmp;

	zx_abs = ft_abs(fractal->zx);
	zy_abs = ft_abs(fractal->zy);
	x_tmp = zx_abs * zx_abs - zy_abs * zy_abs + fractal->cx;
	fractal->zy = 2 * zx_abs * zy_abs + fractal->cy;
	fractal->zx = x_tmp;
}

void	burning_ship(t_fractal *fractal)
{
	int		i;

	i = 0;
	fractal->zx = 0;
	fractal->zy = 0;
	fractal->cx = ((fractal->x - WID / 2.0)
			/ fractal->zoom) + fractal->offset_x;
	fractal->cy = ((fractal->y - LEN / 2.0)
			/ fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iteration)
	{
		calc_burning_ship(fractal);
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4.0)
			break ;
	}
	if (i == fractal->max_iteration)
		putpixels(fractal, fractal->x, fractal->y, 0x000000);
	else
		putpixels(fractal, fractal->x, fractal->y, fractal->color * i);
}

void	put_burning_ship(t_fractal *fractal)
{
	fractal->y = 0;
	while (fractal->y < LEN)
	{
		fractal->x = 0;
		while (fractal->x < WID)
		{
			burning_ship(fractal);
			fractal->x++;
		}
		fractal->x = 0;
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->mlx_window, fractal->img_ptr, 0, 0);
}

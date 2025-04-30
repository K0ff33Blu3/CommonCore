/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:06:24 by miricci           #+#    #+#             */
/*   Updated: 2025/04/30 14:07:29 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_display(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	free(fractal->name);
	free(fractal);
	exit(EXIT_SUCCESS);
}

void	putpixels(t_fractal *fractal, int x, int y, int color)
{
	int	*offset;
	int	index;
	int	pixels_per_line;

	pixels_per_line = fractal->line_len / 4;
	offset = (int *)fractal->img_addr;
	index = y * pixels_per_line + x;
	offset[index] = color;
}

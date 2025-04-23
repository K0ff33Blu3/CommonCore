/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:31:26 by miricci           #+#    #+#             */
/*   Updated: 2025/04/23 20:55:26 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_display(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
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

void	put_image(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->y < LEN)
	{
		while (fractal->x < WID)
		{
			mandelbrot(fractal);
			fractal->x++;
		}
		fractal->x = 0;
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->mlx_window, fractal->img_ptr, 0, 0);
}

int	main(void)
{
	t_fractal *fractal;

	fractal = (t_fractal *) malloc(sizeof(t_fractal));
	if (!fractal)
		return (1);
	init_fractal(fractal);
	init_mlx(fractal);
	init_hooks(fractal);
	put_image(fractal);
	mlx_loop(fractal->mlx_ptr);
	mlx_destroy_image(fractal->mlx_ptr, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->img_ptr);
	free(fractal->mlx_ptr);
	return (0);
}

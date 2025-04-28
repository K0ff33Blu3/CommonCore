/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:31:26 by miricci           #+#    #+#             */
/*   Updated: 2025/04/28 15:55:27 by miricci          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) malloc(sizeof(t_fractal));
	if (!fractal)
		return (1);
	init_fractal(fractal);
	parse_input(argc, argv, fractal);
	init_mlx(fractal);
	init_hooks(fractal);
	if (!ft_strncmp(fractal->name, "mandelbrot", 11))
		put_mandelbrot(fractal);
	else if (!ft_strncmp(fractal->name, "julia", 5))
		put_julia(fractal);
	else if (!ft_strncmp(fractal->name, "burning ship", 12))
		put_burning_ship(fractal);
	mlx_loop(fractal->mlx_ptr);
	close_display(fractal);
	return (0);
}

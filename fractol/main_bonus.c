/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:51:49 by miricci           #+#    #+#             */
/*   Updated: 2025/05/01 13:52:04 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) malloc(sizeof(t_fractal));
	if (!fractal)
		exit (EXIT_FAILURE);
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

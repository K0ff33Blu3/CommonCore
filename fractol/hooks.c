/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:15:30 by miricci           #+#    #+#             */
/*   Updated: 2025/04/28 16:49:38 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_keypress(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_display(fractal);
	else if (keysym == ARROW_UP || keysym == ARROW_DOWN
		|| keysym == ARROW_LEFT || keysym == ARROW_RIGHT)
		move(fractal, keysym);
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		put_mandelbrot(fractal);
	else if (!ft_strncmp(fractal->name, "julia", 5))
		put_julia(fractal);
	else if (!ft_strncmp(fractal->name, "burning ship", 12))
		put_burning_ship(fractal);
	return (0);
}

void	move(t_fractal *fractal, int keysym)
{
	if (keysym == ARROW_UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (keysym == ARROW_DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (keysym == ARROW_LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (keysym == ARROW_RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
}

void	zoom(t_fractal *fractal, int x, int y, int button)
{
	double	zoom_rate;
	double	mouse_re;
	double	mouse_im;

	zoom_rate = 1.1;
	mouse_re = (x - LEN / 2.0) / fractal->zoom + fractal->offset_x;
	mouse_im = (y - WID / 2.0) / fractal->zoom + fractal->offset_y;
	if (button == SCROLL_UP)
		fractal->zoom *= zoom_rate;
	else if (button == SCROLL_DOWN)
		fractal->zoom /= zoom_rate;
	else
		return ;
	fractal->offset_x = mouse_re - (x - LEN / 2.0) / fractal->zoom;
	fractal->offset_y = mouse_im - (y - WID / 2.0) / fractal->zoom;
}

int	on_mouse_scroll(int button, int x, int y, t_fractal *fractal)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom(fractal, x, y, button);
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		put_mandelbrot(fractal);
	else if (!ft_strncmp(fractal->name, "julia", 5))
		put_julia(fractal);
	else if (!ft_strncmp(fractal->name, "burning ship", 12))
		put_burning_ship(fractal);
	return (0);
}

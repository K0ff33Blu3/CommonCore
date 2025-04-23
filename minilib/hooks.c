/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:15:30 by miricci           #+#    #+#             */
/*   Updated: 2025/04/23 21:03:53 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_keypress(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_display(fractal);
	return (0);
}

void	zoom(t_fractal *fractal, int x, int y, int button)
{
	double zoom_rate;
	
	zoom_rate = 1.05;
	if (button == SCROLL_UP)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom * zoom_rate));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom * zoom_rate));
		fractal->zoom *= zoom_rate;
	}
	else if (button == SCROLL_DOWN)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom * zoom_rate));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom * zoom_rate));
		fractal->zoom /= zoom_rate;
	}
	else
		return ;
}

int	on_mouse_scroll(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP || SCROLL_DOWN)
		zoom(fractal, x, y, button);
	put_image(fractal);
	return (0);
}
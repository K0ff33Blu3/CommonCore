/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:31:26 by miricci           #+#    #+#             */
/*   Updated: 2025/04/23 13:48:15 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	close_display(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	putpixels(t_mlx_img *img, int x, int y, int color)
{
	int	*offset;
	int	index;
	int	pixels_per_line;

	pixels_per_line = img->line_len / 4;
	offset = (int *)img->addr;
	index = y * pixels_per_line + x;
	offset[index] = color;
}
// (z * z) + 1

void	calc_mandelbrot(t_mlx_img *img)
{
	int	i;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int	x;
	int	y;
	

	i = 0;
	
}

void	put_image(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < LEN)
	{
		x = 0;
		while (x < WID)
		{
			if (!(y % 100))
				putpixels(&data->img, x, y, 0xffffff);
			else
				putpixels(&data->img, x, y, 0x000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr,
		data->mlx_window, data->img.img_ptr, 0, 0);
}

int	on_keypress(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		close_display(data);
	return (0);
}

int	on_mouse_move(int keysym, int x, int y, t_mlx_data *data)
{
	(void)x;
	(void)y;
	if (keysym == SCROLL_UP)
		data->zoom *= 1.1;
	else if (keysym == SCROLL_DOWN)
		data->zoom /= 0.9;
	return (0);
}

int	main(void)
{
	t_mlx_data data;
	
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.mlx_window = mlx_new_window(data.mlx_ptr, WID, LEN, "New Window");
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WID, LEN);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr,
		&data.img.bits_per_pixel, &data.img.line_len, &data.img.endian);
	put_image(&data);
	mlx_mouse_hook(data.mlx_window, on_mouse_move, &data);
	mlx_hook(data.mlx_window, KeyPress, KeyPressMask, on_keypress, &data);
	mlx_hook(data.mlx_window, DestroyNotify, NoEventMask, close_display, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.img_ptr);
	mlx_destroy_window(data.mlx_ptr, data.mlx_window);
	mlx_destroy_display(data.mlx_ptr);
	free(data.img.img_ptr);
	free(data.mlx_ptr);
	return (0);
}

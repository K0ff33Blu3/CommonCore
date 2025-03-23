/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:31:26 by miricci           #+#    #+#             */
/*   Updated: 2025/03/23 19:53:55 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	on_enter_window(t_mlx_data *data)
{
	(void)data;
	write(1, "Welcome!\n", 9);
	return (0);
}

int	on_leave_window(t_mlx_data *data)
{
	(void)data;
	write(1, "Bye!\n", 5);
	return (0);
}

int	close_display(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	color_screen(t_mlx_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < LEN)
	{
		x = 0;
		while (x < WID)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_window, x, y, color);
			x++;
		}
		y++;
	}
}

int	on_keypress(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	close_display(data);
	else if (keysym == XK_r)
	color_screen(data, 0xff0000);
	else if (keysym == XK_g)
	color_screen(data, 0xff00);
	else if (keysym == XK_b)
	color_screen(data, 0xff); 
	printf("Key %d has been pressed\n", keysym);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img.img_ptr, 0, 0);
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
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	// mlx_put_image_to_window(data.mlx_ptr, data.mlx_window, data.img.img_ptr, 0, 0);
	mlx_hook(data.mlx_window, EnterNotify, EnterWindowMask, on_enter_window, &data);
	mlx_hook(data.mlx_window, LeaveNotify, LeaveWindowMask, on_leave_window, &data);
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
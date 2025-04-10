/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:30:53 by miricci           #+#    #+#             */
/*   Updated: 2025/04/10 17:56:16 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <stdio.h>
# include <stdlib.h>
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
# define WID 640
# define LEN 480


typedef struct s_mlx_img
{
	void	*img_ptr;
	char	*addr;
	int	bits_per_pixel;
	int	line_len;
	int	endian;
}	t_mlx_img;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_mlx_img	img;
}	t_mlx_data;

typedef struct s_fractal
{
	t_mlx_data	data;
	char	*name;
	int	x;
	int	y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zoom;	
}	t_fractal;

int	on_keypress(int keysym, t_mlx_data *data);
int	close_display(t_mlx_data *data);
int	on_enter_window(t_mlx_data *data);
void	color_screen(t_mlx_data *data, int color);
void	putpixels(t_mlx_img *img, int x, int y, int color);

#endif
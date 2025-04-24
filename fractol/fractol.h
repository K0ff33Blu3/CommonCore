/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:30:53 by miricci           #+#    #+#             */
/*   Updated: 2025/04/24 16:29:47 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <float.h>
# include <stddef.h>
# include <unistd.h>
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"

# define WID 640
# define LEN 640

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define BLACK 0x000000
# define WHITE 0xffffff
# define BLUE  0x0000ff
# define GREEN 0x00ff00
# define RED 0xff0000

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*mlx_window;
	void	*img_ptr;
	char	*img_addr;
	char	*name;
	int	bits_per_pixel;
	int	line_len;
	int	endian;
	int	x;
	int	y;
	double	cx;
	double	cy;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int	max_iteration;
	int	color;
}	t_fractal;

int	on_keypress(int keysym, t_fractal *fractal);
int	on_mouse_scroll(int button, int x, int y, t_fractal *fractal);
int	close_display(t_fractal *fractal);
void	put_mandelbrot(t_fractal *fractal);
void	putpixels(t_fractal *fractal, int x, int y, int color);
void	mandelbrot(t_fractal *fractal);
void	init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);
void	init_hooks(t_fractal *fractal);
void	ft_putstr_fd(char *s, int fd);
void	put_julia(t_fractal *fractal);
void	julia(t_fractal *fractal);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char *src);
void	invalid_params(t_fractal *fractal, char *s);

#endif
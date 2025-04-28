/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:30:53 by miricci           #+#    #+#             */
/*   Updated: 2025/04/28 16:57:03 by miricci          ###   ########.fr       */
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
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364

# define COLOR	0xab3428
# define MAX_ITER 120

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
	double	zx;
	double	zy;
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
char	**ft_split(char const *s, char c);
double	ft_atof(const char *nptr);
void	ft_free(void **s, int i);
int	ft_isspace(int c);
int	check_float(char *nptr);
size_t	ft_strlen(const char *s);
void	parse_input(int argc, char **argv, t_fractal *fractal);
void	burning_ship(t_fractal *fractal);
void	put_burning_ship(t_fractal *fractal);
void	move(t_fractal *fractal, int keysym);

#endif
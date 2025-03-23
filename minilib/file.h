/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:30:53 by miricci           #+#    #+#             */
/*   Updated: 2025/03/23 19:35:32 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <stdio.h>
# include <stdlib.h>
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"
# define WID 1920
# define LEN 1080

typedef struct s_mlx_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_img;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_mlx_img	img;
}	t_mlx_data;

int	on_keypress(int keysym, t_mlx_data *data);
int	close_display(t_mlx_data *data);
int	on_enter_window(t_mlx_data *data);

#endif
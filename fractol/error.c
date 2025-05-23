/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:05:54 by miricci           #+#    #+#             */
/*   Updated: 2025/05/01 12:29:26 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_float(char *nptr)
{
	unsigned int	i;

	if (nptr[0] != '+' && nptr[0] != '-' && !ft_isdigit(nptr[0]))
		return (0);
	i = 1;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]) && nptr[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	invalid_params(t_fractal *fractal, char *s)
{
	free(fractal);
	ft_putstr_fd(s, 2);
	exit(1);
}

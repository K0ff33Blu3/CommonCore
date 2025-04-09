/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:22:10 by miricci           #+#    #+#             */
/*   Updated: 2025/04/09 15:31:38 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(char **arg, int **tab)
{
	if (!check_numbers(arg) || !check_double(tab) || !check_limits(tab))
	{
		ft_free((void **)arg, -1);
		ft_free((void **)tab, -1);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	check_numbers(char **nptr)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i][0]))
		{
			if (nptr[i][0] != '+' && nptr[i][0] != '-')
				return (0);
		}
		j = 1;
		while (nptr[i][j])
		{
			if (!ft_isdigit(nptr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_limits(int **nbr)
{
	unsigned int	i;

	i = 0;
	while (nbr[i])
	{
		if (*(nbr[i]) < INT_MIN || *(nbr[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	check_double(int **nbr)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (nbr[i])
	{
		j = 1;
		while (nbr[i + j])
		{
			if (*(nbr[i]) == *(nbr[i + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

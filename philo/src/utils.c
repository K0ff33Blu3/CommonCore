/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:35:29 by miricci           #+#    #+#             */
/*   Updated: 2025/12/04 15:36:07 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	sgn;

	nbr = 0;
	sgn = 1;
	while (ft_isspace(*nptr) == 1)
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			sgn = -1;
		nptr++;
	}
	while (*nptr)
	{
		if (!(*nptr >= 48 && *nptr <= 57))
			return (sgn * nbr);
		nbr = (nbr * 10) + (*nptr - 48);
		nptr++;
	}
	return (sgn * nbr);
}

void	ft_free(void **s, int i)
{
	int	j;

	if (i == -1)
	{
		j = 0;
		while (s[j])
			free(s[j++]);
	}
	else
	{
		while (--i >= 0)
			free(s[i]);
	}
	free(s);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:00:02 by miricci           #+#    #+#             */
/*   Updated: 2025/05/01 13:50:25 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isspace(int c)
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

static double	ft_atodecimal(const char *nptr)
{
	int		value;
	int		mgn;
	int		i;
	double	result;

	i = 0;
	mgn = 1;
	while (i < (int)ft_strlen(nptr))
	{
		mgn *= 10;
		i++;
	}
	value = ft_atoi(nptr);
	result = (double) value / mgn;
	return (result);
}

double	ft_atof(const char *nptr)
{
	char	**n;
	int		integer;
	double	fraction;
	int		sign;

	if (nptr[0] == '-')
		sign = -1;
	else
		sign = 1;
	n = ft_split(nptr, '.');
	integer = ft_atoi(n[0]);
	if (integer < 0)
		integer *= -1;
	fraction = ft_atodecimal(n[1]);
	ft_free((void **)n, -1);
	return ((integer + fraction) * sign);
}

// int main()
// {
// 	char *nbr = "457.2567";

// 	printf("%f\n", ft_atof(nbr));
// 	return(0);
// }

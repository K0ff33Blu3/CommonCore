/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:23:56 by miricci           #+#    #+#             */
/*   Updated: 2024/12/05 19:04:37 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 4294967295)
	{
		ft_putstr("4294967295");
		return(10);
	}
	if (nbr >= 10)
	{
		i++;
		ft_putnbr_unsigned(nbr / 10);
	}
	nbr = (nbr % 10) + 48;
	ft_putchar(nbr);
	return(i++);
}
/*
int	main()
{
	ft_putnbr_unsigned(4294967295);
	return 0;
}
*/
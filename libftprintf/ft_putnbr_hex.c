/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:12:54 by miricci           #+#    #+#             */
/*   Updated: 2024/12/05 19:00:36 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(int nbr)
{
	char	*set;
	int		i;
	
	set = "0123456789abcdef";
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr == -2147483648)
		ft_putnbr_hex(-(nbr / 16));
	if (nbr >= 16)
	{
		i++;
		ft_putnbr_hex(nbr / 16);
	}
	ft_putchar(set[nbr % 16]);
	return (i++)
}
/*
int	main()
{
	ft_putnbr_hex(-2147483648);
	return 0;
}
*/
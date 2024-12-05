/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:01:49 by miricci           #+#    #+#             */
/*   Updated: 2024/12/03 14:02:12 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int	nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr == -2147483648)
	{
		ft_putstr("2147483648");
		return ;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	nbr = (nbr % 10) + 48;
	ft_putchar(nbr);
}
/*
int	main()
{
	ft_putnbr(-2147483648);
	return 0;
}
*/

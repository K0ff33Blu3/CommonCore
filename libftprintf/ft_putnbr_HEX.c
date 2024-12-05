/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_HEX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:50:35 by miricci           #+#    #+#             */
/*   Updated: 2024/12/05 19:12:43 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_HEX(int nbr)
{
	char	*set;
	int	i;
	
	i = 0;
	set = "0123456789ABCDEF";
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr == -2147483648)
	{
		ft_putnbr_hex(-(nbr / 16));
		return (11);
	}
	if (nbr >= 16)
	{
	
		ft_putnbr_hex(nbr / 16);
	}
	ft_putchar(set[nbr % 16]);
	return (i++);
}
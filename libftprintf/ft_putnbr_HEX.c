/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_HEX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:50:35 by miricci           #+#    #+#             */
/*   Updated: 2024/12/04 15:59:48 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_HEX(int nbr)
{
	char	*set;
	
	set = "0123456789ABCDEF";
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr == -2147483648)
		ft_putnbr_hex(-(nbr / 16));
	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16);
	ft_putchar(set[nbr % 16]);
}
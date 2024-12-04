/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:23:56 by miricci           #+#    #+#             */
/*   Updated: 2024/12/03 14:23:58 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_unsigned(unsigned int nbr)
{
	if (nbr == 4294967295)
	{
		ft_putstr("4294967295");
		return ;
	}
	if (nbr >= 10)
		ft_putnbr_unsigned(nbr / 10);
	nbr = (nbr % 10) + 48;
	ft_putchar(nbr);
}
/*
int	main()
{
	ft_putnbr_unsigned(4294967295);
	return 0;
}
*/

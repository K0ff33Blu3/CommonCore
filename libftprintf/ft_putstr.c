/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:34:15 by miricci           #+#    #+#             */
/*   Updated: 2024/12/03 13:40:17 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putstr(const char *s)
{
	while (*s)
		ft_putchar(*s++);
}
/*
int	main()
{
	ft_putstr("CIAO Cuore <3");
	return 0;
}
*/

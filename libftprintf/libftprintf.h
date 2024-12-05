/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:36:48 by miricci           #+#    #+#             */
/*   Updated: 2024/12/04 17:50:18 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

void    ft_putptr(void *ptr);
void	ft_putchar(char c);
void	ft_putnbr(int	nbr);
void	ft_putstr(const char *s);
void	ft_putnbr_HEX(int nbr);
void	ft_putnbr_unsigned(unsigned int nbr);
void	ft_putnbr_hex(int nbr);
int	ft_printf(const char *format, ...);

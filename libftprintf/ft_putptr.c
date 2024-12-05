/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:00:22 by miricci           #+#    #+#             */
/*   Updated: 2024/12/05 16:26:23 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rev_int_tab(char *tab)
{
	char	buffer;
    	int size;
	int	i;

	i = 0;
    	size = ft_strlen(tab);
	while (i < size / 2)
	{
		buffer = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size -1 - i] = buffer;
		i++;
	}
}

static char  *to_hex(unsigned long long nbr)
{
    char	*set;
    char    *hex;
    int     i;
	
    i = 0;
	set = "0123456789abcdef";
    hex = (char *)malloc (sizeof(char) * 16);
    if (!hex)
    {
        return (NULL);
    }
	while (nbr > 0)
    {
		hex[i] = set[nbr % 16];
        nbr /= 16;
        i++;
    }
    ft_strlcat(hex, "x0", ft_strlen(hex) + 3);
    ft_rev_int_tab(hex);
    i += 2;
    hex[i] = '\0';
    return (hex);
}

void    ft_putptr(void *ptr)
{
    unsigned long long   address;

    address = (unsigned long long)ptr;
    ft_putstr(to_hex(address));
    free(to_hex(address));
}
/*
int main()
{
    char a = 'A';
    ft_putptr(&a);
    return (0);
}
*/

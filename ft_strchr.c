/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:52:02 by miricci           #+#    #+#             */
/*   Updated: 2024/11/19 11:52:06 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		else
			s++;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	char	*str = "Milva";
	char	c = 'l';
	
	printf("%s\n", ft_strchr(str, c));
	return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:40:17 by miricci           #+#    #+#             */
/*   Updated: 2025/04/28 15:20:44 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free(void **s, int i)
{
	int	j;

	if (i == -1)
	{
		j = 0;
		while (s[j])
			free(s[j++]);
	}
	else
	{
		while (--i >= 0)
			free(s[i]);
	}
	free(s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_c;
	unsigned char	*src_c;

	if (!dest && !src)
		return (NULL);
	dest_c = (unsigned char *)dest;
	src_c = (unsigned char *)src;
	if (n == 0)
		return (dest);
	while (n > 0)
	{
		*dest_c = *src_c;
		dest_c++;
		src_c++;
		n--;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((int)n == 0)
		return (0);
	if ((int)n < 0)
	{
		if (ft_strlen(s1) >= ft_strlen(s2))
			n = ft_strlen(s1);
		else
			n = ft_strlen(s2);
	}
	while ((int)n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == 0 || *s2 == 0)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		len;

	len = ft_strlen(src);
	dst = (char *) malloc((len + 1) * sizeof(char));
	if (dst == 0)
		return (0);
	ft_memcpy(dst, src, len);
	*(dst + len) = 0;
	return (dst);
}

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_c;
	unsigned char	*src_c;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	dest_c = (unsigned char *)dest;
	src_c = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (dest);
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dst = (char *) malloc((len + 1) * sizeof(char));
	if (dst == 0)
		return (0);
	ft_memcpy(dst, src, len);
	dst[len] = 0;
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*dst;
	unsigned int	len_1;
	unsigned int	len_2;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	dst = (char *)malloc (sizeof(char) * (len_1 + len_2 + 1));
	if (!dst)
		return (NULL);
	if (s1)
		ft_memcpy(dst, s1, len_1);
	if (s2)
		ft_memcpy(dst + len_1, s2, len_2);
	dst[len_1 + len_2] = 0;
	return (dst);
}

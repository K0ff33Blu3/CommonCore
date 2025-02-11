#include "pipex.h"

static int	countwords(char *s, char c)
{
	int	r;
	int	in_word;
	int	i;
	char	quote;

	r = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == 39 || s[i] == 34) && !in_word)
		{
			quote = s[i];
			i++;
			in_word = 1;
			r++;
			while (s[i] && s[i] != quote)
				i++;
			if (s[i] == quote)
				i++;
		}
		if (s[i] != c && in_word == 0)
		{
			r++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (r);
}

static int	word_len(const char *s, unsigned int start, char end)
{
	int	i;

	i = 0;
	while (s[start] && s[start] != end)
	{
		i++;
		start++;
	}
	return (i);
}

static char	**fill_split(char **dest, const char *s, char c, int words)
{
	int	i;
	int	j;
	int	k;
	char	quote;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c)
			j++;
		if (s[j] == 39 || s[j] == 34)
		{
			quote = s[j];
			j++;
			dest[i] = (char *)malloc(sizeof(char) * (word_len(s, j, quote) + 1));
			if (!dest[i])
				return (ft_free(dest, i), NULL);
			k = 0;
			while (s[j] && s[j] != quote)
				dest[i][k++] = s[j++];
			if (s[j] == quote)
				j++;
		}
		else
		{
			dest[i] = (char *)malloc(sizeof(char) * (word_len(s, j, c) + 1));
			if (!dest[i])
				return (ft_free(dest, i), NULL);
			k = 0;
			while (s[j] && s[j] != c)
				dest[i][k++] = s[j++];
		}
		dest[i][k] = '\0';
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**str_split(char *s, char c)
{
	char	**dest;
	int		words;

	if (!s)
		return (NULL);
	words = countwords(s, c);
	dest = (char **)malloc(sizeof(char *) * (words + 1));
	if (!dest)
		return (NULL);
	return (fill_split(dest, s, c, words));
}

/*
int main(int ac, char **av)
{
	char **res;
	int	i;
	
	i = 0;
	if (ac < 2)
	return 1;
	res = str_split(av[1], ' ');
	while(res[i])
	printf("%s\n", res[i++]);
	ft_free(res, -1);
	return 0;
}
*/


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:54:43 by miricci           #+#    #+#             */
/*   Updated: 2025/04/13 14:14:49 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	skip_quote(char *s, int i)
{
	char	quote;

	quote = s[i];
	i++;
	while (s[i] && s[i] != quote)
		i++;
	if (!s[i])
		return (i);
	return (i + 1);
}

static int	countwords(char *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = -1;
	while (s[++i])
	{
		if ((s[i] == '\'' || s[i] == '\"') && !in_word)
		{
			in_word = 1;
			count++;
			i = skip_quote(s, i);
			continue ;
		}
		if (s[i] != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
	}
	return (count);
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
int	main(int argc, char **argv)
{
	char **result;
	int i;
	
	if (argc > 0)
	{
		result = str_split(argv[1], ' ');
		i = 0;
		while (i<3)
		{
			ft_putstr_fd(result[i], 1);
			ft_putstr_fd("\n", 1);
			i++;
		}
	}
	return 0;
}
*/
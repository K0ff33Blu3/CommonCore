/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:54:23 by miricci           #+#    #+#             */
/*   Updated: 2025/03/22 15:54:24 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*make_path(char *str, char *cmd)
{
	char	*part_path;
	char	*path;

	part_path = ft_strjoin(str, "/");
	path = ft_strjoin(part_path, cmd);
	free(part_path);
	free(str);
	return (path);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	**array;
	char	*path;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	array = ft_split(envp[i] + 5, ':');
	i = 0;
	while (array[i])
	{
		path = make_path(array[i], cmd);
		if (!access(path, X_OK))
		{
			while (array[i++])
				free(array[i]);
			return (free(array), path);
		}
		free(path);
		i++;
	}
	free(array);
	if (!access(cmd, X_OK))
		return (cmd);
	return (NULL);
}
/*
int	main(int argc, char **argv, char **envp)
{
	char *path = find_cmd_path("ls", envp);
	printf("%s\n", path);
	free(path);
	return 0;
}
*/
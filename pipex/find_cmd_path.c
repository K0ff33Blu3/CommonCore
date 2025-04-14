/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:54:23 by miricci           #+#    #+#             */
/*   Updated: 2025/04/14 14:41:56 by miricci          ###   ########.fr       */
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
	return (path);
}

char	*find_cmd_path(t_pipex pipex, char **envp)
{
	char	**array;
	char	*path;
	int		i;

	if (!access(pipex.cmd, X_OK))
		return (pipex.cmd);
	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH", 4))
		i++;
	if (!envp[i])
		cmd_not_found(pipex);
	array = ft_split(envp[i] + 5, ':');
	i = 0;
	while (array[i])
	{
		path = make_path(array[i], pipex.cmd);
		if (!access(path, X_OK))
			return (ft_free((void **)array, -1), path);
		free(path);
		i++;
	}
	i = 0;
	while (array[i])
	{
		ft_putstr_fd(array[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
	ft_free((void **)array, -1);
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

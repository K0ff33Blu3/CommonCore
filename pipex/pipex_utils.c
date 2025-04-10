/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:39:02 by miricci           #+#    #+#             */
/*   Updated: 2025/04/10 12:29:02 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all(t_pipex pipex)
{
	close(pipex.in_fd);
	close(pipex.out_fd);
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
}

void	cmd_not_found(t_pipex pipex)
{
	ft_putstr_fd(pipex.cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	ft_free((void **)pipex.cmd_args, -1);
	ft_free((void **)pipex.all_cmds, -1);
	free(pipex.cmd_path);
	free(pipex.cmd);
	exit(127);
}

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	parse_cmd(t_pipex *pipex, char *cmd, char **envp)
{
	if (!(*cmd))
	{
		ft_free((void **)pipex->all_cmds, -1);
		exit(EXIT_FAILURE);
	}
	pipex->cmd_args = str_split(cmd, ' ');
	if (!pipex->cmd_args)
	{
		ft_free((void **)pipex->all_cmds, -1);
		free(pipex->cmd);
		free(pipex->cmd_path);
		ft_error("Split fallita");
	}
	pipex->cmd = ft_strdup(pipex->cmd_args[0]);
	pipex->cmd_path = find_cmd_path(*pipex, envp);
	if (!pipex->cmd_path)
		cmd_not_found(*pipex);
	free(pipex->cmd_args[0]);
	pipex->cmd_args[0] = ft_strdup(pipex->cmd_path);
}

void	exec_command(t_pipex pipex, char **envp)
{
	if (access(pipex.cmd_path, X_OK) != -1)
	{
		if (execve(pipex.cmd_path, pipex.cmd_args, envp) < 0)
		{
			ft_free((void **)pipex.cmd_args, -1);
			free(pipex.cmd);
			free(pipex.cmd_path);
			ft_error("execve");
		}
	}
}

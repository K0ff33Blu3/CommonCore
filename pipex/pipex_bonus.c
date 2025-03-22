/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:35:23 by miricci           #+#    #+#             */
/*   Updated: 2025/03/22 18:15:46 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	last_child(t_pipex pipex, char *cmd, char *outfile, char **envp)
{
	parse_cmd(&pipex, cmd, envp);
	dup2(pipex.pipe[0], STDIN_FILENO);
	close(pipex.pipe[1]);
	if (access(outfile, W_OK) == -1)
	{
		ft_free((void **)pipex.cmd_args, -1);
		free(pipex.cmd);
		free(pipex.cmd_path);
		ft_error(outfile);
	}
	dup2(pipex.out_fd, STDOUT_FILENO);
	close(pipex.out_fd);
	exec_command(pipex, envp);
}

void	ft_fork(t_pipex *pipex, char *cmd, char **envp)
{
	pid_t	pid;
	int		status;

	if (pipe(pipex->pipe) == -1)
		ft_error("pipe");
	pid = fork();
	if (pid < 0)
		ft_error("fork");
	if (pid == 0)
	{
		close(pipex->pipe[0]);
		dup2(pipex->pipe[1], STDOUT_FILENO);
		close(pipex->pipe[1]);
		parse_cmd(pipex, cmd, envp);
		exec_command(*pipex, envp);
	}
	else
	{
		close(pipex->pipe[1]);
		dup2(pipex->pipe[0], STDIN_FILENO);
		close(pipex->pipe[0]);
		waitpid(pid, &status, 0);
	}
}

static void	run_pipex(t_pipex pipex, int argc, char **argv, char **envp)
{
	pid_t	pid2;
	int		status2;
	int		i;

	pipex.in_fd = open(argv[1], O_RDONLY);
	pipex.out_fd = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	i = 2;
	if (access(argv[1], R_OK) == -1)
		ft_error(argv[1]);
	dup2(pipex.in_fd, STDIN_FILENO);
	close(pipex.in_fd);
	while (i < argc - 2)
		ft_fork(&pipex, argv[i++], envp);
	pid2 = fork();
	if (pid2 < 0)
		ft_error("fork");
	if (pid2 == 0)
		last_child(pipex, argv[i], argv[argc - 1], envp);
	close_all(pipex);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2) && WEXITSTATUS(status2))
		exit(WEXITSTATUS(status2));
}

void	here_doc(t_pipex pipex, char **argv)
{
	char	*line;

	pipex.limiter = ft_strjoin(argv[2], "\n");
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_strncmp(line, pipex.limiter, ft_strlen(pipex.limiter)))
			break ;
		ft_putstr_fd(line, pipex.pipe[1]);
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	ft_memset(&pipex, 0, sizeof(t_pipex));
	if (argc >= 5)
	{
		if (!ft_strncmp(argv[1], "here_doc", 8))
			here_doc(pipex, argv);
		else
			run_pipex(pipex, argc, argv, envp);
	}
	else
	{
		ft_putstr_fd("Wrong argument number\n", STDERR_FILENO);
		ft_putstr_fd("Inserire almeno 4 argomenti\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

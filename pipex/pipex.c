#include "pipex.h"
#include <errno.h>

static void	close_all(t_pipex pipex)
{
	close(pipex.in_fd);
	close(pipex.out_fd);
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
}

static void	cmd_not_found(t_pipex pipex)
{
	ft_putstr_fd(pipex.cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	ft_free(pipex.cmd_args, -1);
	free(pipex.cmd_path);
	free(pipex.cmd);
	exit(127);
}

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

static void	first_child(t_pipex pipex, char *cmd, char *infile, char **envp)
{
	pipex.cmd_args = str_split(cmd, ' ');
	pipex.cmd = ft_strdup(pipex.cmd_args[0]);
	pipex.cmd_path = find_cmd_path(pipex.cmd_args[0], envp);
	if (!pipex.cmd_path)
		cmd_not_found(pipex);
	free(pipex.cmd_args[0]);
	pipex.cmd_args[0] = ft_strdup(pipex.cmd_path);
	if (access(infile, R_OK) == -1)
	{
		ft_free(pipex.cmd_args, -1);
		free(pipex.cmd);
		free(pipex.cmd_path);
		ft_error(infile);
	}
	dup2(pipex.in_fd, STDIN_FILENO);
	dup2(pipex.pipe[1], STDOUT_FILENO);
	close_all(pipex);
	if (access(pipex.cmd_path, X_OK) != -1)
	{
		if (execve(pipex.cmd_path, pipex.cmd_args, envp) < 0)
		{
			ft_free(pipex.cmd_args, -1);
			free(pipex.cmd);
			free(pipex.cmd_path);
			ft_error("execve");
		}
	}
}


static void	last_child(t_pipex pipex, char *cmd, char *outfile, char **envp)
{
	pipex.cmd_args = str_split(cmd, ' ');
	pipex.cmd = ft_strdup(pipex.cmd_args[0]);
	pipex.cmd_path = find_cmd_path(pipex.cmd_args[0], envp);
	if (!pipex.cmd_path)
		cmd_not_found(pipex);
	free(pipex.cmd_args[0]);
	pipex.cmd_args[0] = ft_strdup(pipex.cmd_path);
	dup2(pipex.pipe[0], STDIN_FILENO);
	if (access(outfile, W_OK) == -1)
	{
		ft_free(pipex.cmd_args, -1);
		free(pipex.cmd_path);
		free(pipex.cmd);
		ft_error(outfile);
	}
	dup2(pipex.out_fd, STDOUT_FILENO);
	close_all(pipex);
	if (access(pipex.cmd_path, X_OK) != -1)
	{
		if (execve(pipex.cmd_path, pipex.cmd_args, envp) < 0)
		{
			ft_free(pipex.cmd_args, -1);
			free(pipex.cmd_path);
			free(pipex.cmd);
			ft_error("execve");
		}
	}
}


int	main(int argc, char **argv, char **envp)
{
	t_pipex		pipex;
	pid_t		pid1;
	pid_t		pid2;
	int			status1;
	int			status2;

	if (argc == 5)
	{
		if (pipe(pipex.pipe) == -1)
			perror("qualcosa");
		pipex.in_fd = open(argv[1], O_RDONLY);
		pipex.out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
		pid1 = fork();
		if (pid1 < 0)
			ft_error("first fork");
		if (pid1 == 0)
			first_child(pipex, argv[2], argv[1], envp);
		pid2 = fork();
		if (pid2 < 0)
			ft_error("second fork");
		if (pid2 == 0)
			last_child(pipex, argv[3], argv[4], envp);
		close_all(pipex);
		waitpid(pid1, &status1, 0);
		waitpid(pid2, &status2, 0);
		if (WIFEXITED(status2))
		{
			if (WEXITSTATUS(status2))
				exit(WEXITSTATUS(status2));
		}
	}
	else
	{
		ft_putstr_fd("Wrong argument number", STDERR_FILENO);
		ft_putstr_fd("Inserire 4 argomenti", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

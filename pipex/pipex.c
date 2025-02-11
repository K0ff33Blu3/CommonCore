#include "pipex.h"
#include <errno.h>

static void	close_all(t_pipex pipex)
{
	close(pipex.in_fd);
	close(pipex.out_fd);
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
}

static void	first_child(t_pipex pipex, char *cmd, char *infile, char **envp)
{
	pipex.cmd_args = str_split(cmd, ' ');
	pipex.cmd = ft_strdup(pipex.cmd_args[0]);
	pipex.cmd_path = find_cmd_path(pipex.cmd_args[0], envp);
	free(pipex.cmd_args[0]);
	pipex.cmd_args[0] = ft_strdup(pipex.cmd_path);
	if (access(infile, R_OK) == -1)
	{
		ft_free(pipex.cmd_args, -1);
		free(pipex.cmd_path);
		perror("input");
		exit(EXIT_FAILURE);
	}
	dup2(pipex.in_fd, STDIN_FILENO);
	dup2(pipex.pipe[1], STDOUT_FILENO);
	close_all(pipex);
	if (access(pipex.cmd_path, X_OK) != -1)
	{
		if (execve(pipex.cmd_path, pipex.cmd_args, envp) < 0)
		{
			ft_free(pipex.cmd_args, -1);
			free(pipex.cmd_path);
			perror("first execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr_fd("sono qui\n", STDERR_FILENO);
		ft_putnbr_fd(errno, STDERR_FILENO);
		if (errno == EFAULT)
		{
			ft_free(pipex.cmd_args, -1);
			free(pipex.cmd_path);
			ft_putstr_fd(pipex.cmd, STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			exit(127);
		}
		exit(EXIT_FAILURE);
	}
}

static void	last_child(t_pipex pipex, char *cmd, char *outfile, char **envp)
{
	//char buffer[1024];
	pipex.cmd_args = str_split(cmd, ' ');
	pipex.cmd = pipex.cmd_args[0];
	pipex.cmd_path = find_cmd_path(pipex.cmd_args[0], envp);
	pipex.cmd_args[0] = pipex.cmd_path;
	/*
	if (read(pipex.pipe[0], buffer, 1024))
	exit (EXIT_FAILURE);
	printf("%s\n", buffer);	
	*/
	dup2(pipex.pipe[0], STDIN_FILENO);
	if (access(outfile, W_OK) == -1)
	{
		ft_free(pipex.cmd_args, -1);
		free(pipex.cmd_path);
		perror("second access");
		exit(EXIT_FAILURE);
	}
	dup2(pipex.out_fd, STDOUT_FILENO);
	close_all(pipex);
	if (access(pipex.cmd_path, X_OK) != -1)
	{
		if (execve(pipex.cmd_path, pipex.cmd_args, envp) < 0)
		{
			ft_free(pipex.cmd_args, -1);
			free(pipex.cmd_path);
			perror("second execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr_fd("sono qui\n", STDERR_FILENO);
		ft_putnbr_fd(errno, STDERR_FILENO);
		if (errno == EFAULT)
		{
			ft_free(pipex.cmd_args, -1);
			free(pipex.cmd_path);
			ft_putstr_fd(pipex.cmd, STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			exit(127);
		}
		exit(EXIT_FAILURE);
	}
}

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pipex;
	int			fd[2];
	pid_t		pid1;
	pid_t		pid2;
	int	status1;
	int	status2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			perror("qualcosa");
		pipex.in_fd = open(argv[1], O_RDONLY);
		pipex.out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
		//if (pipex.out_fd < 0)
		//	return(perror("output"), EXIT_FAILURE);
		pipex.pipe[0] = fd[0];
		pipex.pipe[1] = fd[1];
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
		if (WIFEXITED(status1))
		{
			printf("child1 normally exited with status %d\n", WEXITSTATUS(status1));
			//exit(WEXITSTATUS(status1));
		}
		else
		{
			printf("child1 brutally exited with status\n");
		}
		waitpid(pid2, &status2, 0);
		if (WIFEXITED(status2))
		{
			printf("child2 exited with status %d\n", WEXITSTATUS(status2));
			exit(WEXITSTATUS(status2));
		}
	}
	else
	{
		ft_putstr_fd("STOCAZZO", 2);
		ft_putstr_fd("STOCAZZO SU TTY", 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}
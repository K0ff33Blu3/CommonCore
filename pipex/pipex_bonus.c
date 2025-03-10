#include "pipex.h"
/*
static void	first_child(t_pipex pipex, char *cmd, char *infile, char **envp)
{
	parse_cmd(&pipex, cmd, envp);
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
	exec_command(pipex, envp);
}
*/

static void	last_child(t_pipex pipex, char *cmd, char *outfile, char **envp)
{
	parse_cmd(&pipex, cmd, envp);
	dup2(pipex.pipe[0], STDIN_FILENO);
	if (access(outfile, W_OK) == -1)
	{
		ft_free(pipex.cmd_args, -1);
		free(pipex.cmd);
		free(pipex.cmd_path);
		ft_error(outfile);
	}
	dup2(pipex.out_fd, STDOUT_FILENO);
	close_all(pipex);
	exec_command(pipex, envp);
}

void	ft_fork(t_pipex pipex, char *cmd, char **envp)
{
	pid_t	pid;
	int	status;
	int	fd[2];

	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid < 0)
		ft_error("fork");
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		parse_cmd(&pipex, cmd, envp);
		exec_command(pipex, envp);
	}
	else
		dup2(fd[0], STDIN_FILENO);
	waitpid(pid, &status, 0);
}

static void	run_pipex(t_pipex pipex, int argc, char **argv, char **envp)
{
	pid_t	pid2;
	int		status2;
	int	i;

	pipex.in_fd = open(argv[1], O_RDONLY);
	pipex.out_fd = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	i = 2;
	if (access(argv[1], R_OK) == -1)
	{
		ft_free(pipex.cmd_args, -1);
		free(pipex.cmd);
		free(pipex.cmd_path);
		ft_error(argv[1]);
	}
	dup2(pipex.in_fd, STDIN_FILENO);
	while (i < argc - 2)
		ft_fork(pipex, argv[i++], envp);
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

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc >= 5)
		run_pipex(pipex, argc, argv, envp);
	else
	{
		ft_putstr_fd("Wrong argument number\n", STDERR_FILENO);
		ft_putstr_fd("Inserire almeno 4 argomenti\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

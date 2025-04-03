#include "pipex.h"

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

static void	run_pipex(t_pipex pipex, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

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
	if (WIFEXITED(status2) && WEXITSTATUS(status2))
		exit(WEXITSTATUS(status2));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	ft_memset(&pipex, 0, sizeof(t_pipex));
	if (argc == 5)
		run_pipex(pipex, argv, envp);
	else
	{
		ft_putstr_fd("Wrong argument number\n", STDERR_FILENO);
		ft_putstr_fd("Inserire 4 argomenti\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		pipe[2];
	char	*cmd;
	char	*cmd_path;
	char	**cmd_args;
}	t_pipex;

char	*find_cmd_path(char *cmd, char **envp);
char	**str_split(char *s, char c);
char	**fill_split(char **dest, const char *s, char c, int words);
void	close_all(t_pipex pipex);
void	cmd_not_found(t_pipex pipex);
void	ft_error(char *str);
void	parse_cmd(t_pipex *pipex, char *cmd, char **envp);
void	exec_command(t_pipex pipex, char **envp);

#endif
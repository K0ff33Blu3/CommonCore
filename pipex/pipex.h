#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"

char	*find_cmd_path(char *cmd, char **envp);
char	**str_split(char *s, char c);

typedef struct s_pipex
{
	int	in_fd;
	int	out_fd;
	char	*cmd;
	char	*cmd_path;
	char	**cmd_args;
	int	pipe[2];
} t_pipex;

#endif
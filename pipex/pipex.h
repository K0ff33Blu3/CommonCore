/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:06:32 by miricci           #+#    #+#             */
/*   Updated: 2025/05/05 14:16:48 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		n_cmd;
	char	*limiter;
	char	*cmd;
	char	*cmd_path;
	char	**cmd_args;
	char	**all_cmds;
}	t_pipex;

char	*find_cmd_path(t_pipex *pipex, char **envp);
char	**str_split(char *s, char c);
char	**fill_split(char **dest, const char *s, char c, int words);
void	close_std(void);
void	close_pipe(t_pipex *pipex);
void	cmd_not_found(t_pipex *pipex);
void	ft_error(char *str);
void	parse_cmd(t_pipex *pipex, char *cmd, char **envp);
void	exec_command(t_pipex pipex, char **envp);
void	input_doc(t_pipex *pipex, char **argv, int argc);
void	here_doc(t_pipex *pipex, char **argv, int argc);

#endif
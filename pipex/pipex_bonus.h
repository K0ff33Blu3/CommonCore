/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:38:39 by miricci           #+#    #+#             */
/*   Updated: 2025/03/22 16:11:22 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	char	*limiter;
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
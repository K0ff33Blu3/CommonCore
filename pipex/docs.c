/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   docs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:47:03 by miricci           #+#    #+#             */
/*   Updated: 2025/04/02 14:47:12 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	input_doc(t_pipex *pipex, char **argv, int argc)
{
	int	i;

	i = 0;
	pipex->all_cmds = (char **) malloc(sizeof(char *) * (argc - 2));
	if (!pipex->all_cmds)
		ft_error("malloc");
	while (i < argc - 3)
	{
		pipex->all_cmds[i] = ft_strdup(argv[2 + i]);
		i++;
	}
	pipex->all_cmds[i] = NULL;
	pipex->n_cmd = i;
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (access(argv[1], R_OK) == -1)
		ft_error(argv[1]);
	dup2(pipex->in_fd, STDIN_FILENO);
	close(pipex->in_fd);	
}

void	here_doc(t_pipex *pipex, char **argv, int argc)
{
	char	*line;
	int		i;

	i = -1;
	pipex->all_cmds = (char **) malloc(sizeof(char *) * (argc - 3));
	if (!pipex->all_cmds)
		ft_error("malloc");
	while (++i < argc - 4)
		pipex->all_cmds[i] = ft_strdup(argv[3 + i]);
	pipex->all_cmds[i] = NULL;
	pipex->n_cmd = i;
	if (pipe(pipex->pipe) == -1)
		ft_error("pipe");
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(line, pipex->limiter, ft_strlen(pipex->limiter)))
			break ;
		ft_putstr_fd(line, pipex->pipe[1]);
		free(line);
	}
	close(pipex->pipe[1]);
	dup2(pipex->pipe[0], STDIN_FILENO);
	close(pipex->pipe[0]);
	free(line);
}

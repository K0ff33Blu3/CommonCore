/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   docs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:47:03 by miricci           #+#    #+#             */
/*   Updated: 2025/05/05 14:13:28 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	pipex->out_fd = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (pipex->in_fd == -1)
	{
		pipex->in_fd = open("/dev/null", O_RDONLY);
		perror(argv[1]);
	}
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
	pipex->out_fd = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
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
	free(line);
	dup2(pipex->pipe[0], STDIN_FILENO);
	close_pipe(pipex);
}

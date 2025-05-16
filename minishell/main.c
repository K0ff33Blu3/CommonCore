/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:54:51 by miricci           #+#    #+#             */
/*   Updated: 2025/05/16 01:21:09 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	int i = 0;
	char *cmd_line;
	
	cmd_line = (char *)malloc(sizeof(char) * 1024);
	if (!cmd_line)
		exit(EXIT_FAILURE);
	while(1)
	{
		ft_putstr_fd(PROMPT, STDIN_FILENO);
		cmd_line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(cmd_line, "pwd", 3))
		{
			pwd(envp);
		}
	}
	free(cmd_line);
	return 0;
}
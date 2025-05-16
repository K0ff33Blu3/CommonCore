/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:45:51 by miricci           #+#    #+#             */
/*   Updated: 2025/05/16 01:41:52 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(char **envp)
{
	int	i;
	int	cmp;

	i = 0;
	while(*envp)
	{
		if(!ft_strncmp(*envp, "PWD", 2))
		{	
			ft_putendl_fd((*envp + 4), STDOUT_FILENO);
		}
		envp++;
	}
}
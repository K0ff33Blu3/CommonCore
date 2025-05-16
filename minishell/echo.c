/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:53:43 by miricci           #+#    #+#             */
/*   Updated: 2025/05/16 00:59:51 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char *str, int n)
{
	if (n == 0)
		ft_putendl_fd(str, STDOUT_FILENO);
	else
	{
		ft_putstr_fd(str, STDOUT_FILENO);
		ft_putendl_fd("%", STDOUT_FILENO); 	
	}
}
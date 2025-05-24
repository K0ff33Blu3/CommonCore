/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:45:56 by miricci           #+#    #+#             */
/*   Updated: 2025/05/24 14:20:31 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char *s)
{
	
	while (s)
		write(STDERR_FILENO, s++, 1);
	write(STDERR_FILENO, " ERROR\n", 7); 
}

void	clean(t_data *data, t_philo **philo)
{
	if (data->fork)
		ft_free((void **)data->fork, -1);
	if (data)
		free(data);
	if (philo)
		ft_free((void **)philo, -1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:00:27 by miricci           #+#    #+#             */
/*   Updated: 2025/05/24 14:23:50 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data		*parsing(int size, char **array)
{
	t_data		*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nbr_philo = ft_atoi(array[1]);
	data->time_to_die = ft_atoi(array[2]);
	data->time_to_eat = ft_atoi(array[3]);
	data->time_to_sleep = ft_atoi(array[4]);
	data->fork = init_forks(data->nbr_philo);
	if (size == 6)
		data->times_philo_must_eat = ft_atoi(array[5]);
	else
		data->times_philo_must_eat = INT_MAX;
	return (data);
}

t_fork	**init_forks(int nbr)
{
	t_fork	**fork;
	int		i;
	
	fork = (t_fork **)malloc(sizeof(t_fork *) * nbr);
	i = 0;
	while (i < nbr)
	{
		fork[i] = (t_fork *)malloc(sizeof(t_fork));
		if (!fork[i])
			return (ft_free((void **)fork, i), error_message("MALLOC"), NULL);
		fork[i]->status = 1;
		pthread_mutex_init(&fork[i]->mutex, NULL);
		i++;
	}
}
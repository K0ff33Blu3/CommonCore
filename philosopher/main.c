/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:57:23 by miricci           #+#    #+#             */
/*   Updated: 2025/05/24 14:26:55 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_void)
{
	t_philo *philo;

	philo = (t_philo *)philo_void;
	while (1)
	{
		eating(philo);
		if (philo->meals >= philo->data->times_philo_must_eat)
			exit(0);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

t_philo	*init_philo(t_data *data, int i)
{
	t_philo	*philo;
	
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (error_message("MALLOC"), NULL);
	philo->data = data;
	philo->philo_id = i + 1;
	philo->meals = 0;
	philo->fork_l = data->fork[i];
	philo->fork_r = data->fork[(i + 1) % data->nbr_philo];
	return (philo);
}

t_philo	**init_threads(t_data *data)
{
	pthread_t	*th;
	t_philo		**philos;
	int		i;
	
	th = (pthread_t *)malloc(sizeof(pthread_t) * data->nbr_philo);
	philos = (t_philo **)malloc(sizeof(t_philo *) * data->nbr_philo);
	if (!th || !philos)
		return (error_message("MALLOC"), NULL);
	i = -1;
	while (++i < data->nbr_philo)
	{
		philos[i] = init_philo(data, i);
		if (!philos[i])
			return (ft_free((void **)philos, i), error_message("MALLOC"), NULL);
		if (pthread_create(&th[i], NULL, &routine, philos[i]))
			return (error_message("CREATE THREAD"), NULL);
	}
	i = -1;
	while (++i < data->nbr_philo)
	{
		if (pthread_join(th[i], NULL))
			return (error_message("JOIN THREAD"), NULL);
	}
	free(th);
	return (philos);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_philo		**philos;

	if (argc > 6 || argc < 4)
		printf("Error\n");
	else
	{
		data = parsing(argc, argv);
		philos = init_threads(data);
		clean(data, philos);
	}
	return (0);
}
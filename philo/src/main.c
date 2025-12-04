/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:29:30 by miricci           #+#    #+#             */
/*   Updated: 2025/12/04 20:00:44 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_meals(void *pointer)
{
	t_philo **philo;
	t_data	data;
	int	i;

	philo = (t_philo **)pointer;
	data = (t_data)(*philo)->data;
	while (1)
	{
		i = -1;
		while (++i < data.nbr_philo)
			if(!philo[i]->is_done)
				break ;
		if (i == data.nbr_philo)
			exit(EXIT_SUCCESS);
	}
}

t_data	*parse_data(char **token)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nbr_philo = ft_atoi(token[1]);
	data->time_to_die = ft_atoi(token[2]);
	data->time_to_eat = ft_atoi(token[3]);
	data->time_to_sleep = ft_atoi(token[4]);
	if (token[5])
		data->meals_to_eat = ft_atoi(token[5]);
	else
		data->meals_to_eat = INT_MAX;
	pthread_mutex_init(&(data->death_mutex), NULL);
	return (data);
}
void	set_isdead(t_philo *philo)
{
	pthread_mutex_lock(&(philo->death_lock));
	philo->is_dead = true;
	printf("%ld philosopher %d died\n", get_time(), philo->id);
	pthread_mutex_unlock(&(philo->death_lock));
}


void	*monitor_thread(void *philo_ptr)
{
	t_philo	*philo;
	uint64_t	time;
	uint64_t	death_time;
	bool	is_eating;

	philo = (t_philo *)philo_ptr;
	while (1)
	{
		time = get_time();
		pthread_mutex_lock(&(philo->meal_lock));
		death_time = philo->death_time;
		is_eating = philo->is_eating;
		pthread_mutex_unlock(&(philo->meal_lock));
		if (time > death_time && !is_eating)
		{
			set_isdead(philo);
			exit(EXIT_SUCCESS);
		}
		usleep(1000);
	}
	return (NULL);
}

bool	get_isdead(t_philo *philo)
{
	bool	status;
	
	pthread_mutex_lock(&(philo->death_lock));
	status = philo->is_dead;
	pthread_mutex_unlock(&(philo->death_lock));
	return (status);
}

bool	get_done(t_philo *philo)
{
	bool	status;
	
	pthread_mutex_lock(&(philo->meal_lock));
	status = philo->is_done;
	pthread_mutex_unlock(&(philo->meal_lock));
	return (status);
}

void	*routine(void *philo_ptr)
{
	t_philo *philo;
	pthread_t	tid;

	philo = (t_philo *)philo_ptr;
	if (pthread_create(&tid, NULL, &monitor_thread, (void *)philo))
		return (printf("Error\n"), NULL);
	pthread_detach(tid);
	while (!get_isdead(philo) || !get_done(philo))
	{
		eat(philo);
		sleep_ft(philo);
		think(philo);
	}
	return (NULL);
}

t_philo	*init_philo(t_data *data, t_fork **fork, int i)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->data = *data;
	philo->tid = (pthread_t *)malloc(sizeof(pthread_t));
	if (!philo->tid)
		return (NULL);
	philo->left_fork = fork[i];
	philo->right_fork = fork[i + 1];
	if (i == data->nbr_philo - 1)
		philo->right_fork = fork[0];
	philo->id = i + 1;
	philo->start_time = get_time();
	philo->death_time = philo->start_time + data->time_to_die;
	pthread_mutex_init(&philo->death_lock, NULL);
	pthread_mutex_init(&philo->meal_lock, NULL);
	philo->meals = 0;
	philo->is_eating = false;
	philo->is_dead = false;
	philo->is_done = false;
	if (pthread_create(philo->tid, NULL, &routine, (void *)philo))
		return (printf("Error\n"), NULL);
	return (philo);
}

t_fork	*init_fork(void)
{
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	pthread_mutex_init(&(fork->mutex), NULL);
	fork->status = true;
	return (fork);
}
int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	**philo;
	t_fork	**fork;
	pthread_t	tid;
	int	i;

	i = -1;
	if (ac < 5 || ac > 6)
		return (printf("Error\n"), 1);
	else
	{
		data = parse_data(av);
		if (!data)
		return (1);
		fork = (t_fork **)malloc(sizeof(t_fork) * data->nbr_philo);
		philo = (t_philo **)malloc(sizeof(t_philo) * data->nbr_philo);
		if (!fork || !philo)
		return (1);
		while (++i < data->nbr_philo)
		{
			fork[i] = init_fork();
			if (!fork[i])
				return (ft_free((void **)fork, i), 1);
		}
		i = -1;
		while (++i < data->nbr_philo)
		{
			philo[i] = init_philo(data, fork, i);
			if (!philo[i])
				return (ft_free((void **)philo, i), 1);
		}
		if (pthread_create(&tid, NULL, &monitor_meals, (void *)philo))
			return (printf("Error\n"), 1);
		pthread_detach(tid);
		i = -1;
		while (++i < data->nbr_philo)
		{
			if (pthread_join(*(philo[i]->tid), NULL))
				return (ft_free((void **)philo, -1), ft_free((void **)fork, -1), 1);
		}
		i = -1;
		while (++i < data->nbr_philo)
			pthread_mutex_destroy(&(fork[i]->mutex));
		ft_free((void **)fork, -1);
		ft_free((void **)philo, -1);
	}
	return (0);
}

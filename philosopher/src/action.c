/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:03:15 by miricci           #+#    #+#             */
/*   Updated: 2025/05/24 17:38:58 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	die(t_philo *philo)
{
	print_action(philo, DIE);
	ft_exit(philo->data, philo);
}

void	eating(t_philo *philo)
{
	int	time;

	take_fork(philo);
	time = get_time();
	usleep(philo->data->time_to_eat * 1000);
	print_action(philo, EAT);
	philo->meals++;
	philo->is_eating = 1;
	philo->death_time = time + philo->data->time_to_die;
	pthread_mutex_unlock(&philo->fork_l->mutex);
	philo->fork_l->status = 1;
	pthread_mutex_unlock(&philo->fork_r->mutex);
	philo->fork_r->status = 1;
}

void	thinking(t_philo *philo)
{
	print_action(philo, THINK);
}

void	sleeping(t_philo *philo)
{
	struct timeval tv;

	philo->is_eating = 0;
	gettimeofday(&tv, NULL);
	print_action(philo, SLEEP);
	usleep(philo->data->time_to_sleep * 1000);
}

void	take_fork(t_philo *philo)
{
	if (philo->fork_l->status && philo->fork_r->status)
	{
		pthread_mutex_lock(&philo->fork_l->mutex);
		pthread_mutex_lock(&philo->fork_r->mutex);
		philo->fork_l->status = 0;
		philo->fork_r->status = 0;
		print_action(philo, FORK);
	}
}
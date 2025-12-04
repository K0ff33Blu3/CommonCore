/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:57:40 by miricci           #+#    #+#             */
/*   Updated: 2025/12/04 20:15:31 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	think(t_philo *philo)
{
	printf("%ld philosopher %d is thinking\n", get_time(), philo->id);
}

void	sleep_ft(t_philo *philo)
{
	printf("%ld philosopher %d is sleeping\n", get_time(), philo->id);
	ft_usleep(philo->data.time_to_sleep);
}

void	grab_fork(t_fork *fork)
{
	pthread_mutex_lock(&(fork->mutex));
	fork->status = false;
}
void	drop_fork(t_fork *fork)
{
	pthread_mutex_unlock(&(fork->mutex));
	fork->status = true;
}

void	grab(t_philo *philo)
{
	if (philo->id % 2)
	{
		grab_fork(philo->left_fork);
		printf("%ld philosopher %d has taken a fork\n", get_time(), philo->id);
		grab_fork(philo->right_fork);
		printf("%ld philosopher %d has taken a fork\n", get_time(), philo->id);
	}
	else
	{
		grab_fork(philo->right_fork);
		printf("%ld philosopher %d has taken a fork\n", get_time(), philo->id);
		grab_fork(philo->left_fork);
		printf("%ld philosopher %d has taken a fork\n", get_time(), philo->id);
	}
}

void	drop(t_philo *philo)
{
	if (philo->id % 2)
	{
		drop_fork(philo->left_fork);
		drop_fork(philo->right_fork);
	}
	else
	{
		drop_fork(philo->right_fork);
		drop_fork(philo->left_fork);
	}
}

void	eat(t_philo *philo)
{
	grab(philo);
	pthread_mutex_lock(&(philo->meal_lock));
	philo->is_eating = true;
	philo->death_time = get_time() + philo->data.time_to_die;
	philo->meals++;
	if (philo->meals >= philo->data.meals_to_eat)
		philo->is_done = true;
	printf("%ld philosopher %d is eating meal %d\n", get_time(), philo->id, philo->meals);
	pthread_mutex_unlock(&(philo->meal_lock));
	ft_usleep(philo->data.time_to_eat);
	drop(philo);
}

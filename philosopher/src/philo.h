/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:51:21 by miricci           #+#    #+#             */
/*   Updated: 2025/05/24 18:33:39 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_fork
{
	int	status;
	pthread_mutex_t	mutex;
}	 t_fork;


typedef	struct s_data
{
	int	nbr_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_philo_must_eat;
	t_fork	**fork;
}	t_data;

typedef struct s_philo
{
	t_data	*data;
	int	philo_id;
	int	death_time;
	int	meals;
	int	is_eating;
	int	is_dead;
	t_fork	*fork_l;
	t_fork	*fork_r;
}	t_philo;

t_philo	*init_threads(t_data *data);
void	*routine(void *philo);
t_data		*parsing(int size, char **array);
t_fork	**init_forks(int nbr);
t_philo	init_philo(t_data *data, int i);
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	take_fork(t_philo *philo);
void	print_action(t_philo *philo, const char *action);
void	error_message(char *s);
void	clear_data(t_data *data, t_philo *philo);
void	die(t_philo *philo);
void	ft_exit(t_data *data, t_philo *philo);

// utils.c
int	ft_atoi(const char *nptr);
void	ft_free(void **s, int i);
int	get_time();

#endif
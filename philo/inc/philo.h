/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:30:24 by miricci           #+#    #+#             */
/*   Updated: 2025/12/04 19:47:29 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_data
{
	int	nbr_philo;
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	int	meals_to_eat;
	bool	someone_died;
	pthread_mutex_t	death_mutex;
}	t_data;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	bool	status;
} t_fork;

typedef	struct s_philo
{
	int	id;
	t_data	data;
	pthread_t	*tid;
	t_fork	*left_fork;
	t_fork	*right_fork;
	uint64_t	start_time;
	uint64_t	death_time;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meal_lock;
	int	meals;
	bool	is_eating;
	bool	is_dead;
	bool	is_done;
}	t_philo;


// actions.c
void	think(t_philo *philo);
void	sleep_ft(t_philo *philo);
void	grab_fork(t_fork *fork);
void	drop_fork(t_fork *fork);
void	grab(t_philo *philo);
void	drop(t_philo *philo);
void	eat(t_philo *philo);

// time_handling.c
uint64_t get_time(void);
void	ft_usleep(int time);

// utils.c
int	ft_atoi(const char *nptr);
void	ft_free(void **s, int i);

bool	get_isdead(t_philo *philo);


#endif
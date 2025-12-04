/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:01:41 by miricci           #+#    #+#             */
/*   Updated: 2025/12/04 15:30:31 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t get_time(void)
{
	struct timeval	tv;
	uint64_t	now;
	
	if (gettimeofday(&tv, NULL))
		return (printf("Error\n"), 0);
	now = tv.tv_sec * 1000;
	now += tv.tv_usec / 1000;
	return (now);
}

void	ft_usleep(int time)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < (uint64_t)time)
		usleep(500);	
}
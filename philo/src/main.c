/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:29:30 by miricci           #+#    #+#             */
/*   Updated: 2025/12/09 13:40:32 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	**philo;
	t_data	*data;

	if (ac < 5 || ac > 6)
		return (printf("Error\n"), 1);
	else
	{
		data = init_data(av);
		if (!data->nbr_philo)
			return (clean_data(data), printf("Error\n"), 1);
		philo = init_simulation(data);
		set_threads(philo, data);
		cleanup(data, philo);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:22 by miricci           #+#    #+#             */
/*   Updated: 2025/03/10 15:29:28 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**arg;
	int		**tab;

	if (ac == 1)
		return (0);
	av++;
	tab = parse_integer(av, ac - 1);
	if (!check_numbers(av) || !check_double(tab) || !check_limits(tab))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	arg = create_list((void **)tab, ac - 1);
	print_list(arg);
	//check_small_stacks(arg)
	ft_lstclear(arg, free);
	free(tab);
	return (0);
}

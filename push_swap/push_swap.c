/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:22 by miricci           #+#    #+#             */
/*   Updated: 2025/03/13 10:13:02 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		**tab;
	int		**ind;
	int	list_size;

	if (ac == 1)
		return (0);
	av++;
	tab = parse_integer(av, ac - 1);
	if (!check_numbers(av) || !check_double(tab) || !check_limits(tab))
	{
		ft_free((void **)tab, -1);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ind = normalize_tab(tab, ac -1);
	ft_free((void **)tab, -1);
	stack_a = create_list((void **)ind, ac - 1);
	stack_b = create_list(NULL, 0);
	list_size = ft_lstsize(*stack_a);
	// print_list(stack_a, "STACK_A");
	if (list_size < 6)
		check_small_stacks(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	// print_list(stack_a, "STACK_A");
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	free(ind);
	return (0);
}

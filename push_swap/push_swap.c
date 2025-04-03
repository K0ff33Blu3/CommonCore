/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:22 by miricci           #+#    #+#             */
/*   Updated: 2025/03/31 15:12:14 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		**tab;
	int		**ind;
	char	**arg;
	int	n_arg;

	if (ac == 1)
		return (0);
	av++;
	if (ac == 2)
		arg = ft_split(*av, ' ');
	else
		arg = av;
	n_arg = array_size((void **)arg);
	tab = parse_integer(arg, n_arg);
	if (!check_numbers(arg) || !check_double(tab) || !check_limits(tab))
	{
		ft_free((void **)arg, -1);
		ft_free((void **)tab, -1);
		ft_putstr_fd("Error not digit\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ind = normalize_tab(tab, n_arg);
	ft_free((void **)arg, -1);
	ft_free((void **)tab, -1);
	stack_a = create_list((void **)ind, n_arg);
	stack_b = create_list(NULL, 0);
	if (n_arg < 6)
		check_small_stacks(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	free(ind);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:22 by miricci           #+#    #+#             */
/*   Updated: 2025/04/09 15:57:50 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**define_input_style(int ac, char **av)
{
	char	**arg;

	if (ac == 1)
		return (0);
	av++;
	if (ac == 2)
		arg = ft_split(*av, ' ');
	else
		arg = av;
	return (arg);
}

t_list	**set_stack_a(char **arg, int n_arg)
{
	t_list	**stack_a;
	int		**tab;
	int		**ind;

	tab = parse_integer(arg, n_arg);
	ind = normalize_tab(tab, n_arg);
	check_error(arg, tab);
	stack_a = create_list((void **)ind, n_arg);
	free(ind);
	ft_free((void **)arg, -1);
	ft_free((void **)tab, -1);
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**arg;
	int		n_arg;

	arg = define_input_style(ac, av);
	n_arg = array_size((void **)arg);
	stack_a = set_stack_a(arg, n_arg);
	stack_b = create_list(NULL, 0);
	if (n_arg < 6)
		check_small_stacks(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	ft_lstclear(stack_a, free);
	free(stack_b);
	return (0);
}

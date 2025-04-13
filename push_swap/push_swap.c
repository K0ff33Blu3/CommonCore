/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:22 by miricci           #+#    #+#             */
/*   Updated: 2025/04/13 12:01:09 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**define_input_style(int ac, char **av)
{
	char	**arg;
	int	i;
	
	i = 0;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	av++;
	if (ac == 2)
		arg = ft_split(*av, ' ');
	else
	{
		arg = (char **)malloc(sizeof(char *) * (array_size((void **)av) + 1));
		if (!arg)
			return (NULL);
		while (*av)
		{
			arg[i] = ft_strdup(*av);
			if (!arg[i])
				return(ft_free((void **)arg, i), NULL);
			i++;
			av++;			
		}
		arg[i] = NULL;
	}
	return (arg);
}

t_list	**set_stack_a(char **arg, int n_arg)
{
	t_list	**stack_a;
	long		**tab;
	int		**ind;

	tab = parse_integer(arg, n_arg);
	check_error(arg, tab);
	ind = normalize_tab(tab, n_arg);
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
	if (!*arg)
		return(free(arg), 0);
	if (n_arg == 1)
		return(ft_free((void **)arg, -1), 0);
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

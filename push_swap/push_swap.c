/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:22 by miricci           #+#    #+#             */
/*   Updated: 2025/03/05 15:11:41 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		**tab;

	av++;
	tab = parse_integer(av, ac - 1);
	stack_a = create_list((void **)tab, ac - 1);
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (1);
	print_list(stack_a);
	print_list(stack_b);
	push(stack_a, stack_b);
	print_list(stack_a);
	print_list(stack_b);
	push(stack_a, stack_b);
	print_list(stack_a);
	print_list(stack_b);
	push(stack_a, stack_b);
	print_list(stack_a);
	print_list(stack_b);
	push(stack_b, stack_a);
	print_list(stack_a);
	print_list(stack_b);
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	free(tab);
	return (0);
}

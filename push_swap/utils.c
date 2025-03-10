/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:56:18 by miricci           #+#    #+#             */
/*   Updated: 2025/03/10 15:31:15 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_list(t_list *node)
{
	while (node)
	{
		if (*(int *)(node->content) > *(int *)(node->next->content))
			return (0);
		node = node->next;
	}
	return (1);
}

void	sorted_exit(t_list **stack)
{
	if (is_sorted_list(*stack))
	{
		ft_printf("SORTED!");
		exit(EXIT_SUCCESS);
	}
}

void	check_small_stacks(t_list **stack)
{
	int	size;

	size = ft_lstsize(*stack);
	if (size == 1)
		exit (EXIT_SUCCESS);
	if (size == 2)
	{
		sorted_exit(stack);
		sa(stack);
		sorted_exit(stack);
	}
	if (size == 3)
	{
		sorted_exit(stack);
		
	}
}


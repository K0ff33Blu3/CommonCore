/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:56:18 by miricci           #+#    #+#             */
/*   Updated: 2025/03/31 15:07:38 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_list(t_list *node)
{
	while (node && node->next)
	{
		if (*(int *)(node->content) > *(int *)(node->next->content))
			return (0);
		node = node->next;
	}
	return (1);
}

int	array_size(void **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

static void	sort_three(t_list **stack)
{
	int	value[3];

	if (ft_lstsize(*stack) != 3)
		return ;
	if (is_sorted_list(*stack))
		return ;
	value[0] = *(int *)((*stack)->content);
	value[1] = *(int *)((*stack)->next->content);
	value[2] = *(int *)((*stack)->next->next->content);
	if (value[0] > value[1] && value[0] < value[2])
		sa(stack);
	else if (value[0] > value[1] && value[1] > value[2])
	{
		sa(stack);
		rra(stack);
	}
	else if (value[0] > value[2] && value[1] < value[2])
		ra(stack);
	else if (value[0] < value[1] && value[0] > value[2])
		rra(stack);
	else if (value[0] < value[2] && value[1] > value[2])
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	count;

	if (is_sorted_list(*stack_a))
		exit (EXIT_SUCCESS);
	count = 0;
	while (count < 2)
	{
		if (*(int *)((*stack_a)->content) < 2)
		{
			count++;
			pb(stack_a, stack_b);
		}
		else
			ra(stack_a);
	}
	if (is_sorted_list(*stack_b))
		sb(stack_b);
	if (ft_lstsize(*stack_a) == 2)
	{
		if (!is_sorted_list(*stack_a))
			sa(stack_a);
	}
	else
		sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	check_small_stacks(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 1)
		exit (EXIT_SUCCESS);
	if (size == 2)
	{
		if (!is_sorted_list(*stack_a))
			sa(stack_a);
	}
	if (size == 3)
		sort_three(stack_a);
	if (size == 5 || size == 4)
		sort_five(stack_a, stack_b);
}

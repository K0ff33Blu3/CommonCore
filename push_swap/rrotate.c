/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:20:43 by miricci           #+#    #+#             */
/*   Updated: 2025/03/12 14:20:55 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_list **head)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *head;
	while ((tmp->next)->next)
		tmp = tmp->next;
	last = ft_lstlast(*head);
	last->next = *head;
	tmp->next = NULL;
	*head = last;
}

void	rra(t_list **stack_a)
{
	rrotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rrotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:53:16 by miricci           #+#    #+#             */
/*   Updated: 2025/03/05 15:10:55 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_a;
	t_list	*node_b;

	ft_printf("------------EXEC PUSH---------------\n");
	if (!stack_a || !stack_b)
		return ;
	node_a = *stack_a;
	node_b = *stack_b;
	*stack_b = node_a;
	*stack_a = node_a->next;
	node_a->next = node_b;
}

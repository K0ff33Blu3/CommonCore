/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:52:52 by miricci           #+#    #+#             */
/*   Updated: 2025/03/05 19:03:05 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list **stack)
{
	t_list	*node;
	t_list *nxt_node;

	node = *stack;
	nxt_node = node->next;
	if (node->content > nxt_node->content && nxt_node->content < nxt_node->next->content)
	
		
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:53:03 by miricci           #+#    #+#             */
/*   Updated: 2025/03/05 14:53:06 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **head)
{
	t_list	*last;
	t_list	*tmp;

	ft_printf("\n------------EXEC ROT---------------\n");
	tmp = (*head)->next;
	last = ft_lstlast(*head);
	last->next = *head;
	(last->next)->next = NULL;
	*head = tmp;
}

void	rrotate(t_list **head)
{
	t_list	*tmp;
	t_list	*last;

	ft_printf("------------EXEC RROT---------------\n");
	tmp = *head;
	while ((tmp->next)->next)
		tmp = tmp->next;
	last = ft_lstlast(*head);
	last->next = *head;
	tmp->next = NULL;
	*head = last;
}

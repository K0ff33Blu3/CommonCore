/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:50 by miricci           #+#    #+#             */
/*   Updated: 2025/03/04 15:28:52 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_list(t_list **head)
{
	t_list	*node;
	int		*value;
	int		i;

	i = 1;
	node = *head;
	ft_printf("\n------------PRINT LIST---------------\n");
	while (node)
	{
		value = node->content;
		ft_printf("node %d: \n", i);
		ft_printf("content: %d\n", *value);
		ft_printf("next: %p\n", node->next);
		node = node->next;
		i++;
	}
	ft_printf("------------PRINT LIST---------------\n\n");
}

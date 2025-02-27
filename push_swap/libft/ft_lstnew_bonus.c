/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:59:07 by miricci           #+#    #+#             */
/*   Updated: 2024/11/30 10:59:24 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc (sizeof(t_list *));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int	main(void)
{
	char *content = "Milva";
	t_list *nodo = ft_lstnew((void *)content);
	
	if(nodo)
	{
		printf("Content: %s\nNext: %p\n", (char *)nodo->content, nodo->next);
		free(nodo);
	}
	else
		printf("ERROR");
	return (0);
}
*/

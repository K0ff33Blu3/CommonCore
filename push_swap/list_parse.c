/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:14 by miricci           #+#    #+#             */
/*   Updated: 2025/04/13 12:06:57 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	**parse_integer(char **nbrs, int tab_size)
{
	long	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(long *) * (tab_size + 1));
	if (!tab)
		return (NULL);
	while (i < tab_size)
	{
		tab[i] = malloc(sizeof(long));
		if (!tab[i])
			return (ft_free((void **)tab, i), NULL);
		*tab[i] = ft_atol(nbrs[i]);
		i++;
	}
	tab[tab_size] = NULL;
	return (tab);
}

t_list	**create_list(void **args, int list_size)
{
	t_list	**head;
	t_list	*node;
	int		i;

	head = (t_list **)malloc(sizeof(t_list *));
	if (!head)
		return (NULL);
	if (!list_size)
	{
		*head = NULL;
		return (head);
	}
	*head = ft_lstnew(args[0]);
	if (!*head)
		return (free(head), NULL);
	node = *head;
	i = 0;
	while (++i < list_size)
	{
		node->next = ft_lstnew(args[i]);
		if (!node->next)
			return (ft_lstclear(head, free), NULL);
		node = node->next;
	}
	return (head);
}

void	print_list(t_list **head, char *list_name)
{
	t_list	*node;
	int		*value;
	int		i;

	if (!head)
		return ;
	i = 1;
	node = *head;
	ft_printf("\n------------%s---------------\n", list_name);
	while (node)
	{
		value = node->content;
		ft_printf("node %d: \n", i);
		ft_printf("content: %d\n", *value);
		ft_printf("next: %p\n", node->next);
		node = node->next;
		i++;
	}
	ft_printf("------------%s---------------\n\n", list_name);
}

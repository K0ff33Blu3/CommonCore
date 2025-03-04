#include "push_swap.h"

int	**parse_integer(char **nbrs, int tab_size)
{
	int	**tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int *) * tab_size);
	if (!tab)
		return (NULL);
	while (i < tab_size)
	{
		tab[i] = malloc(sizeof(int));
		if (!tab[i])
			return (ft_free((void **)tab, i), NULL);
		*tab[i] = ft_atoi(nbrs[i]);
		i++;
	}
	return (tab);
}

t_list **create_list(void **args, int list_size)
{
    t_list **head;
    t_list *node;
    int i;
    
    head = (t_list **)malloc(sizeof(t_list *));
    if (!head)
	return (NULL);
    *head = ft_lstnew(args[0]);
    if (!*head)
	return (free(head), NULL);
    node = *head;
    i = 1;
    while (i < list_size)
    {
        node->next = ft_lstnew(args[i]);
	if (!node->next)
		return(ft_lstclear(head, free), free(head), NULL);
        node = node->next;
        i++;
    }
    return (head);
}

void   print_list(t_list **head)
{
    t_list *node;
    int	*value;

    node = *head;
    int i = 1;
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


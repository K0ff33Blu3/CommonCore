#include "push_swap.h"

t_list *create_list(char **args, int list_size)
{
    t_list *head;
    t_list *node;
    int i;
    
    head = ft_lstnew(args[0]);
    node = head;
    i = 1;
    while (i < list_size)
    {
        node->next = ft_lstnew(args[i]);
        // printf("%s\n", (char *)(node->content));
        node = node->next;
        i++;
    }
    return (head);
}

void   print_list(t_list **head)
{
    t_list *node;

    node = *head;
    int i = 1;
    while (node)
    {
        ft_printf("%d: ", i);
        ft_printf("%s\n", (char *)(node->content));
        ft_printf("%s\n", (char *)(node->next));
        node = node->next;
        i++;
    }
}


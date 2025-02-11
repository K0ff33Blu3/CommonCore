#include "libft_bonus.h"

void    del_content(void *content)
{
    free(content);
}

void    *to_uppercase(void *content)
{
    char *str = (char *)content;
    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
        str++;
    }
    return(content);
}

void    to_lowercase(void *content)
{
    char *str = (char *)content;
    while (*str)
    {
        if (*str >= 'A' && *str <= 'Z')
            *str += 32;
        str++;
    }
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_list;
    t_list  *new_node;
    t_list  *new_content;
    t_list  *tmp;

    new_list = NULL;
    if (!lst | !f | !del)
        return (NULL);
    while (lst)
    {
        new_content = f(lst->content);
        if (!new_content)        
            return NULL;
        new_node = ft_lstnew(new_content);
        if (!new_node)
            return NULL;
        if (!new_list)
            new_list = new_node;
        else
        {
            tmp = new_list;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = new_node;
        }
        lst = lst->next;
    }
    return (new_list);
}

int main(void)
{
    t_list *node1 = (t_list *)malloc(sizeof(t_list));
    t_list *node2 = (t_list *)malloc(sizeof(t_list));
    t_list *node3 = (t_list *)malloc(sizeof(t_list));
    t_list *tmp;
    t_list  *new_list;

    if (!node1 || !node2 || !node3)
        return (1);

    // Inizializza i nodi
    node1->content = strdup("hello");
    node1->next = node2;

    node2->content = strdup("world");
    node2->next = node3;

    node3->content = strdup("list");
    node3->next = NULL;

    // Stampa la lista prima dell'iterazione
    printf("Before ft_lstmap:\n");
    tmp = node1;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }

    // Applica ft_lstiter con la funzione to_uppercase
    new_list = ft_lstmap(node1, to_uppercase, del_content);
    //t_lstiter(node1, to_lowercase);

    // Stampa la lista dopo l'iterazione
    printf("\nAfter ft_lstmap:\n");
    while (new_list)
    {
        printf("%s\n", (char *)new_list->content);
        new_list = new_list->next;
    }
    return (0);
}
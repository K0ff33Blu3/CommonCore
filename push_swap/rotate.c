#include "push_swap.h"

void	rotate(t_list **head)
{
	ft_printf("\n------------EXEC ROT---------------\n");

	t_list	*last;
	t_list	*tmp;

	tmp = (*head)->next;
	last = ft_lstlast(*head);
	last->next = *head;
	(last->next)->next = NULL;
	*head = tmp;
}

void	rrotate(t_list **head)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*last;

	ft_printf("\n------------EXEC RROT---------------\n");
	
	tmp = 
	last = ft_lstlast(*head);
	last->next = *head;
	first->next = tmp;
	*head = last;
}
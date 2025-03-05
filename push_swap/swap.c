#include "push_swap.h"

void	swap(t_list **head)
{
	t_list *first;
	t_list	*second;

	ft_printf("\n------------EXEC SWAP---------------\n");

	
	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

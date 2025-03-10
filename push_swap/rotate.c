#include "push_swap.h"

static void	rotate(t_list **head)
{
	t_list	*last;
	t_list	*tmp;

	tmp = (*head)->next;
	last = ft_lstlast(*head);
	last->next = *head;
	(last->next)->next = NULL;
	*head = tmp;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
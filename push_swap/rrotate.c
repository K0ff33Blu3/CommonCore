#include "push_swap.h"

static void	rrotate(t_list **head)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*last;
	
	tmp = 
	last = ft_lstlast(*head);
	last->next = *head;
	first->next = tmp;
	*head = last;
}

void	rra(t_list **stack_a)
{
	rrotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rrotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
}
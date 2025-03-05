#include "push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_a;
	t_list	*node_b;

	if (!stack_a || !stack_b || !*stack_b)
		return ;
	node_a = *stack_a;
	node_b = *stack_b;
	*stack_b = node_a;
	*stack_a = node_a->next;
	node_a->next = node_b;
}

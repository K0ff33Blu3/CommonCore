#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		**tab;


	
	av++;
	tab = parse_integer(av, ac - 1);
	stack_a = create_list((void **)tab, ac - 1);
	print_list(stack_a);
	//rrotate(stack_a);
	print_list(stack_b);
	ft_lstclear(stack_a, free);
	free(tab);
	return (0);
}
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*arg;
	
	av++;
	arg = create_list(av, ac);
	print_list(&arg);
	return (0);
}
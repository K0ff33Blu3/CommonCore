#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**arg;
	int	**tab;

	av++;
	tab = parse_integer(av, ac - 1);
	arg = create_list((void **)tab, ac - 1);
	print_list(arg);
	return (0);
}
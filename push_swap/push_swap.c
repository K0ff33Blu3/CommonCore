#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*arg;
	arg = *create_list((ac - 2), av++);
	print_list(arg);
	return (0);
}
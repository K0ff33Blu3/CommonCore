#include "push_swap.h"

t_list	**create_list(int stack_size, char **nptr)
{
	t_list	**list;
	t_list	*node;
	int	i;

	i = 0;
	*list = NULL;
	while (i < stack_size)
	{
		node = ft_lstnew(ft_atoi(nptr[i]));
		if (!node)
		// liberare nodi precedenti
			return (NULL);
		ft_lstadd_back(list, node);
		i++;
	}
	return (list);
}

void	print_list(t_list *list)
{
	while(list->next)
	{
		ft_putnbr_fd(list->content, STDOUT_FILENO);
		ft_putchar_fd("\n", STDOUT_FILENO);
		list->next;
	}
}

int	main(int ac, char **av)
{
	create_list((ac - 2), av);
	
	return (0);
}
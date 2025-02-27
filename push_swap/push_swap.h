#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_nlist
{
	int	nbr;
	struct s_nlist *next;
}	t_nlist;

t_list *create_list(char **args, int list_size);
void   print_list(t_list **head);

#endif
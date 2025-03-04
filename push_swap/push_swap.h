#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

t_list	**create_list(void **args, int list_size);
void   print_list(t_list **head);
int	**parse_integer(char **nbrs, int tab_size);


#endif
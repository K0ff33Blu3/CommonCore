/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:05 by miricci           #+#    #+#             */
/*   Updated: 2025/04/09 15:57:37 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_data
{
	int	value;
	int	index;	
}	t_data;

t_list	**create_list(void **args, int list_size);
t_list	**set_stack_a(char **arg, int n_arg);
char	**define_input_style(int ac, char **av);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	check_small_stacks(t_list **stack_a, t_list **stack_b);
void	check_error(char **arg, int **tab);
int		**parse_integer(char **nbrs, int tab_size);
int		**normalize_tab(int **tab, int tab_size);
int		is_sorted_list(t_list *node);
int		check_double(int **nbr);
int		check_limits(int **nbr);
int		check_numbers(char **nptr);
void	radix_sort(t_list **stack_a, t_list **stack_b);

#endif

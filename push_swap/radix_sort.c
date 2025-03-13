/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:19:09 by miricci           #+#    #+#             */
/*   Updated: 2025/03/13 10:15:07 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**normalize_tab(int **tab, int tab_size)
{
	int	i;
	int	j;
	int	**norm;
	int	value;

	norm = malloc(sizeof(int *) * tab_size);
	if (!norm)
		return (NULL);
	i = 0;
	while (i < tab_size)
	{
		value = *tab[i];
		j = 0;
		norm[i] = ft_calloc(1, sizeof(int));
		if (!norm[i])
			return (ft_free((void **)norm, i), NULL);
		while (j < tab_size)
		{
			if (*tab[j] < value)
				*norm[i] = *norm[i] + 1;
			j++;
		}
		i++;
	}
	return (norm);
}

static unsigned int	bit_counter(int nbr)
{
	int	bits;

	bits = 0;
	while (nbr)
	{
		bits++;
		nbr >>= 1;
	}
	return (bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	unsigned int	stack_size;
	unsigned int	i;
	unsigned int	j;
	unsigned int	bits;
	int				value;

	stack_size = ft_lstsize(*stack_a);
	bits = bit_counter(stack_size);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < stack_size)
		{
			value = *(int *)((*stack_a)->content);
			if (((value >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

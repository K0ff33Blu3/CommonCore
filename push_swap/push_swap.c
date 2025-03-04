/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:22 by miricci           #+#    #+#             */
/*   Updated: 2025/03/04 18:55:45 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**arg;
	int		**tab;

	av++;
	tab = parse_integer(av, ac - 1);
	arg = create_list((void **)tab, ac - 1);
	print_list(arg);
	rrotate(arg);
	print_list(arg);
	ft_lstclear(arg, free);
	free(tab);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:05 by miricci           #+#    #+#             */
/*   Updated: 2025/03/04 18:45:34 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#  define STR(X) #X

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

t_list	**create_list(void **args, int list_size);
void	print_list(t_list **head);
void	swap(t_list **head);
void	rotate(t_list **head);
void	rrotate(t_list **head);
void	push(t_list **stack_a, t_list **stack_b);
int		**parse_integer(char **nbrs, int tab_size);

#endif
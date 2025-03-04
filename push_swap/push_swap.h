/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:05 by miricci           #+#    #+#             */
/*   Updated: 2025/03/04 15:28:09 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

t_list	**create_list(void **args, int list_size);
void	print_list(t_list **head);
int		**parse_integer(char **nbrs, int tab_size);

#endif

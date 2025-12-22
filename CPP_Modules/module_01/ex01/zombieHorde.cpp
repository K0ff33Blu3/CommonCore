/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:21:07 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 18:52:25 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
		
	Zombie* horde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
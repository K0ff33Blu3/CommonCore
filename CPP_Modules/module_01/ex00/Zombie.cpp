/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:55:41 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 17:50:10 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name) {
	std::cout << this->name + " created." << std::endl;
	return ;
}

Zombie::~Zombie( void ) {
	std::cout << this->name + " destroyed." << std::endl;
	return ;
}

void	Zombie::announce( void ) const {
	std::cout << this->name + ": BraiiiiiiinnnzzzZ" << std::endl;
	return ;
}
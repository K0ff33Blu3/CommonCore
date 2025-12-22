/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:20:31 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 18:41:45 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {
	std::cout << "Zombie created." << std::endl;
	return ;
}

Zombie::~Zombie( void ) {
	std::cout << this->name + " destroyed." << std::endl;
	return ;
}

void	Zombie::setName( std::string nm ) {
	this->name = nm;
	return ;
}

void	Zombie::announce( void ) const {
	std::cout << this->name + ": BraiiiiiiinnnzzzZ" << std::endl;
	return ;
}
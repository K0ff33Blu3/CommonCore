/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:09:15 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 21:46:10 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : name(name), weapon(NULL) {
	
	std::cout << "\033[90m" << this->name << " built.\033[0m" << std::endl;
	return ;
}

HumanB::~HumanB() {
	
	std::cout << "\033[90m" << this->name << " destroyed.\033[0m" << std::endl;
	return ;
}

void	HumanB::attack( void ) {
	
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon( Weapon& weapon ) {
	
	this->weapon = &weapon;
	return ;
}

// void	HumanB::setName( std::string name ) {
	
// 	this->name = name;
// 	return ;
// }
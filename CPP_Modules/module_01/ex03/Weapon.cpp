/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:30:49 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 20:18:59 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string weaponType ) : type(weaponType) {
	
	std::cout << "\033[90m" << this->type << " built.\033[0m" << std::endl;
	return ;
}

Weapon::~Weapon() {
	
	std::cout << "\033[90m" << this->type + " destroyed.\033[0m" << std::endl;
	return ;
}

std::string Weapon::getType( void ) const {
	
	std::string type = this->type;
	return (type);
}

void	Weapon::setType( std::string value ) {

	this->type = value;
	return ;
}
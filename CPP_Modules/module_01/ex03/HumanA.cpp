/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:31:46 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 21:36:16 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : name(name), weapon(weapon) {
	
	std::cout << "\033[90m" << this->name << " built.\033[0m" << std::endl;
	return ;
}

HumanA::~HumanA() {
	
	std::cout << "\033[90m" << this->name << " destroyed.\033[0m" << std::endl;
	return ;
}

void	HumanA::attack( void ) {
	
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
	return ;
}
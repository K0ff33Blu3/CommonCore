/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:46:22 by miricci           #+#    #+#             */
/*   Updated: 2026/01/08 18:09:29 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	
	std::cout << "Harl is born." << std::endl;
	
	Harl::table[0].string = "DEBUG"; Harl::table[0].fn = &Harl::debug; Harl::table[0].kind = DEBUG;
	Harl::table[1].string = "INFO"; Harl::table[1].fn = &Harl::info; Harl::table[1].kind = INFO;
	Harl::table[2].string = "WARNING"; Harl::table[2].fn = &Harl::warning; Harl::table[2].kind = WARNING;
	Harl::table[3].string = "ERROR"; Harl::table[3].fn = &Harl::error; Harl::table[3].kind = ERROR;
	
	return ;
}

Harl::~Harl() {
	
	std::cout << "Harl is dead." << std::endl;
	return ;
}

void	Harl::debug( void ) {

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
	return ;
}

void	Harl::info( void ) {

	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
	return ;
}

void	Harl::warning( void ) {

	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
	return ;
}

void	Harl::error( void ) {

	std::cout << "This is unacceptable! I want to speak to the manager now!\n" << std::endl;
	return ;
}

void	Harl::complain( std::string level ) {

	for (size_t i = 0; i < 4; i++)
	{
		if (level == this->table[i].string) {
			
			std::cout << "[ " << this->table[i].string << " ]" << std::endl;
			(this->*table[i].fn)();
			return ;
		}
	}
	std::cout << "Insert valid argument." << std::endl;
}

Harl::Complain	Harl::parseEntry( std::string level ) {
	
	for (size_t i = 0; i < 4; i++)
		if (level == this->table[i].string) return this->table[i].kind;
	return UNKNOWN;
}
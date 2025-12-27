/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:50:34 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 23:30:05 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "\033[90mPhonebook built\033[0m" << std::endl;
	this->current_amount = 0;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "\033[90mPhonebook destroyed\033[0m" << std::endl;
}

void	PhoneBook::addContact(void) {
	if (this->current_amount >= 8)
		std::cout << std::endl << "\033[33mAttention! PhoneBook is full. This contact will overwrite some stuff.\033[0m]" << std::endl;
	this->items[this->current_amount % 8].setNewContact();
	std::cout << "\033[32m✔ New contact created!\033[0m" << std::endl;
	items[this->current_amount % 8].index = this->current_amount % 8;
	this->current_amount++;
}

void	PhoneBook::showContacts(void) {
	if (this->current_amount == 0) {
		std::cout << std::endl << "\033[33mPhoneBook is empty\033]0m" << std::endl << std::endl;
		return ;
	}
	
	int	index;
	
	std::cout << std::endl << std::setw(10) << "\033[36m index\033[0m" << "\033[90m|\033[0m" 
			  				<< std::setw(10) << "First Name" << "\033[90m|\033[0m"
			 				<< std::setw(10) << "Last Name" << "\033[90m|\033[0m"
			 				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; this->current_amount < 8 ? i < this->current_amount : i < 8; i++) {
		this->items[i].getShortContact();
	}
	
	while (1)
	{	
		std::string tmp;
		
		std::cout << std::endl << "To see contact, insert corresponding INDEX: ";
		std::getline(std::cin, tmp);
		
		if (!isDigitOnly(tmp)) {
			std::cout << "\033[31m✘ Insert valid index\033[0m" << std::endl;
			continue ; 
		}
		std::stringstream ss(tmp);
		ss >> index;
		if (index >= 0 && this->current_amount < 8 ? index < this->current_amount : index < 8)
			break ;
		else
			std::cout << "\033[31m✘ Insert valid index\033[0m" << std::endl;
		}
		this->items[index].getLongContact();
}


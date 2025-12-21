/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:37:30 by miricci           #+#    #+#             */
/*   Updated: 2025/12/21 21:04:14 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) {
	std::cout << "\033[90mContact built\033[0m" << std::endl;
	return ;
}

Contact::~Contact(void) {
	std::cout << "\033[90mContract destroyed\033[0m" << std::endl;
	return ;
}

void	Contact::setNewContact(void) {
	// std::cin.ignore();
	std::cout << std::endl << "Enter First Name: ";
	std::getline(std::cin, this->firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, this->lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, this->nickname);
	while (1) {
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, this->phoneNumber);
		if (check_digits(this->phoneNumber))
			break ;
		else
			std::cout << "\033[31m✘ Insert valid phone number\033[0m" << std::endl;
	}
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, this->darkestSecret);
}

void	Contact::getShortContact(void) {
	std::cout << std::setw(10) << "\033[36m" << this->index << "\033[0m" << "\033[90m|\033[0m"
			  << std::setw(10) << ((this->firstName.length() < 10) ? (this->firstName) : (this->firstName.substr(0, 8) + ".")) << "\033[90m|\033[0m" 
			  << std::setw(10) << ((this->lastName.length() < 10) ? (this->lastName) : (this->lastName.substr(0, 8) + ".")) << "\033[90m|\033[0m" 
			  << std::setw(10) << ((this->nickname.length() < 10) ? (this->nickname) : (this->nickname.substr(0, 8) + ".")) << std::endl;
}

void	Contact::getLongContact(void) {
	std::cout << std::endl << "First Name: " << this->firstName << std::endl
							<< "Last Name: " << this->lastName << std::endl
							<< "Nickname: " << this->nickname << std::endl
							<< "Phone Number: " << this->phoneNumber << std::endl
							<< "Darkest Secret: " << this->darkestSecret << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:18:41 by miricci           #+#    #+#             */
/*   Updated: 2026/01/13 12:33:44 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

bool	isDigitOnly(std::string str) {
	for (std::string::iterator it = str.begin(); it < str.end(); ++it) {
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

int	main(void) {
	std::string cmd;
	PhoneBook myPhoneBook;
	
	myPhoneBook.current_amount = 0;
	std::cout << std::endl << "\033[95mWelcome to PhoneBook! :)\033[0m" << std::endl;
	while (1) {
		std::cout << std::endl <<"Write ADD to add new contact, SEARCH to see contact list, EXIT to quit." << std::endl;
		std::getline(std::cin, cmd);
		
		if (cmd == "ADD") {
			myPhoneBook.addContact();
		}
		else if (cmd == "SEARCH") {
			myPhoneBook.showContacts();
		}
		else if (cmd == "EXIT") {
			std::cout << std::endl << "\033[95mBye! :)\033[0m" << std::endl;
			break ;
		}
		else
			std::cout << std::endl << "I'm sorry, my vocabulary is very low..." << std::endl;
	}
	return 0;
}
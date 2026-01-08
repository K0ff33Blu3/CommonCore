/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:45:55 by miricci           #+#    #+#             */
/*   Updated: 2026/01/08 15:49:32 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void ) {

	std::string	entry;
	Harl	harl;
	
	std::cout << "Welcome to Harl's Karen phase. Please insert the kind of complain you'd like to make." << std::endl;
	std::cin >> entry;
	harl.complain(entry);
}
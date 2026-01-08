/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:08:44 by miricci           #+#    #+#             */
/*   Updated: 2026/01/08 18:09:12 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string	toUpper( char *entry ) {
	
	int i = -1;
	
	while (entry[++i])
		entry[i] = std::toupper(entry[i]);
	return entry;
}

int	main( int ac, char **av ) {

	if (ac != 2)
		return (1);
	
	Harl	harl;
	std::string s(toUpper(av[1]));
	
	switch (harl.parseEntry(s))
	{
	case Harl::DEBUG:
		harl.complain("DEBUG");
	case Harl::INFO:
		harl.complain("INFO");
	case Harl::WARNING:
		harl.complain("WARNING");
	case Harl::ERROR:
		harl.complain("ERROR");
	default:
		break;
	}	
}
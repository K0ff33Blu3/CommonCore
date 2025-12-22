/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:20:48 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 19:08:12 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

bool	isDigitOnly(std::string str) {
	for (std::string::iterator it = str.begin(); it < str.end(); ++it) {
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

int	main( void ) {
	
	Zombie* horde;
	std::string	input;
	int	N;

	while (1) {
		std::cout << "How many zombies would you like, sir?" << std::endl;
		std::getline(std::cin, input);
		if (isDigitOnly(input))
			break ;
		else
			std::cout << "Please, insert valid number." << std::endl;
	}
	std::stringstream ss(input);
	ss >> N;
	
	horde = zombieHorde(N, "Franco");
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	
	delete[] horde;
	
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:13:47 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 19:27:19 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {

	std::string brainSays = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brainSays;
	std::string&	stringREF = brainSays;
	
	std::cout << "Memory address of brainSays: " << &brainSays << std::endl;
	std::cout << "Memory address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
	
	std::cout << std::endl;

	std::cout << "Value of brainSays: " << brainSays << std::endl;
	std::cout << "Value of stringPTR: " << stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;
	
	return 0;
}

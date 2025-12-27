/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:33:29 by miricci           #+#    #+#             */
/*   Updated: 2025/12/21 12:54:08 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
// using namespace std;

int	main(int argc, char **argv) {
	// controllo sul numero di argomenti
	if (argc != 2) {
		std::cerr << "Inserire un argomento\n";
		return 1;
	}
	// assegnazione di dell'argomento a s
	std::string s = argv[1];
	// utilizzo un ciclo perche il metodo toupper() appartiene alla classe char 
		
	for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
        	*it = std::toupper(*it);
	}
	std::cout << s << std::endl;
	return 0;
}
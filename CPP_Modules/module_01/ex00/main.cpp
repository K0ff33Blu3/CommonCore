/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:48:03 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 18:10:26 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
	Zombie	*heapZombie;

	std::cout << "Let's spot the difference!" << std::endl;
	heapZombie = newZombie("heapGiaLoSai");
	heapZombie->announce();
	delete heapZombie;
	randomChump("stackDiZona");
	return 0;
}
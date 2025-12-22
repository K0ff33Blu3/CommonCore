/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:49:27 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 18:05:54 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie( std::string nm );
	~Zombie( void );
	
	void	announce( void ) const;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
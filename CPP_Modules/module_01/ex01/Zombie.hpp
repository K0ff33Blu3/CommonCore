/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:19:44 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 19:07:39 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>

class Zombie
{
private:
	std::string name;
public:
	Zombie( void );
	~Zombie( void );
	
	void	setName( std::string nm );
	void	announce( void ) const;
};

Zombie* zombieHorde( int N, std::string name );

#endif
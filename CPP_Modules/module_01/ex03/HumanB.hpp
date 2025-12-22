/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:40:45 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 21:47:29 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon*	weapon;
public:
	HumanB( std::string name );
	~HumanB();
	
	void	attack();
	void	setWeapon( Weapon& weapon );
};

#endif
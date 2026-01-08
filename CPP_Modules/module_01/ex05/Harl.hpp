/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:46:14 by miricci           #+#    #+#             */
/*   Updated: 2026/01/07 21:00:56 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	
	typedef	void (Harl::*Handler)();
	
	struct Entry
	{
		std::string	string;
		Handler			fn;
	};
	
	Entry table[4];
	
public:
	Harl();
	~Harl();
		
	void	complain( std::string level );
};

#endif
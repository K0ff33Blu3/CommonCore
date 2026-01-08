/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:46:14 by miricci           #+#    #+#             */
/*   Updated: 2026/01/08 17:01:23 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
public:
	Harl();
	~Harl();
		
	void	complain( std::string level );
	
	enum Complain {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		UNKNOWN
	};
	
	Complain parseEntry( std::string level );
	
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
		Complain	kind;
	};
	
	Entry table[4];
};

#endif
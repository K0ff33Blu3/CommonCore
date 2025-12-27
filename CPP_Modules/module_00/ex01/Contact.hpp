/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:27:52 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 19:00:49 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		int	index;
		
		Contact(void);
		~Contact(void);
		
		void	setNewContact(void);
		void	getShortContact(void);
		void	getLongContact(void);
		
};

bool	isDigitOnly(std::string str);

#endif
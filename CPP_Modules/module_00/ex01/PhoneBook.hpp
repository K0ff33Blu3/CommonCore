/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miricci <miricci@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:27:33 by miricci           #+#    #+#             */
/*   Updated: 2025/12/22 23:30:31 by miricci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>

# include "Contact.class.hpp"

class PhoneBook {
	public:
		Contact items[8];
		int	current_amount;
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	showContacts(void);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:52:00 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/02 13:26:17 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {

private:
	struct ComplainMap {
		const char *level;
		void (Harl::*function)();
	};

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	ComplainMap _complains[4];
	
public:
	Harl();
	void complain( std::string level);

};

#endif
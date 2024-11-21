/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:33:45 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/21 14:54:41 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain & src);
	Brain & operator=(const Brain & src);
	~Brain();

};

#endif // BRAIN_HPP
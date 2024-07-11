/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:33:45 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/11 12:35:08 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

using std::string;

class Brain {
private:
	string ideas[100];

public:
	Brain();
	Brain(const Brain & src);
	Brain & operator=(const Brain & src);
	~Brain();

};

#endif // BRAIN_HPP
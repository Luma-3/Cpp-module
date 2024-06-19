/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:45:40 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/19 18:22:09 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

using std::string;

class Weapon {

private:

	string type;
	
public:

	Weapon(string type);
	~Weapon();

	const string &getType() const;
	void setType(string type_p);
};

#endif
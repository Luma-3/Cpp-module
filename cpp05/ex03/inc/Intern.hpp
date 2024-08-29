/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:01:56 by luma              #+#    #+#             */
/*   Updated: 2024/08/29 12:48:54 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);
	~Intern();

	AForm *makeForm(const std::string name, const std::string target);
};

#endif // INTERN_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:16:33 by luma              #+#    #+#             */
/*   Updated: 2024/08/29 12:52:35 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);	
	~Bureaucrat();

	Bureaucrat(const std::string &name, const unsigned int grade);
	
	int getGrade() const;
	std::string getName() const;

	void promotion();
	void demotion();

	void signForm(AForm &form);

	void executeForm(AForm const & form);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	

private:
	const std::string _name;
	unsigned int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);




#endif // BUREAUCRAT_HPP
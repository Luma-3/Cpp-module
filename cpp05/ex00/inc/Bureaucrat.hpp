/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:16:33 by luma              #+#    #+#             */
/*   Updated: 2024/07/15 15:50:41 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>

using std::string;
using std::ostream;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);	
	~Bureaucrat();

	Bureaucrat(const string &name, const unsigned int grade);
	
	int getGrade() const;
	string getName() const;

	void promotion();
	void demotion();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	

private:
	const string _name;
	unsigned int _grade;
};

ostream &operator<<(ostream &out, const Bureaucrat &bureaucrat);




#endif // BUREAUCRAT_HPP
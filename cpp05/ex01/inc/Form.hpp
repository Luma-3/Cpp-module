/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:53:49 by luma              #+#    #+#             */
/*   Updated: 2024/08/03 13:48:11 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <ostream>

#include "Bureaucrat.hpp"

using std::string;
using std::ostream;

class Bureaucrat;

class Form
{
public:
	Form();
	Form(const Form &src);
	Form &operator=(const Form &src);
	~Form();

	Form(const string name, const int grade_sign, const int grade_exec);

	// Getters
	
	string	getName() const;
	bool	isSigned() const;
	int		getGradeToSign() const;
	int		getGradeToExecute() const;

	void	beSigned(const Bureaucrat bureaucrat);

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
	bool _is_signed;
	const int _grade_to_sign;
	const int _grade_to_execute;
};

ostream &operator<<(ostream& out, const Form &form);

#endif // FORM_HPP
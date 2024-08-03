/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:53:49 by luma              #+#    #+#             */
/*   Updated: 2024/08/03 19:48:07 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <ostream>

#include "Bureaucrat.hpp"

using std::string;
using std::ostream;

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	virtual ~AForm();

	AForm(const string name, const string target, const int grade_sign, const int grade_exec);

	// Getters
	
	string	getName() const;
	bool	isSigned() const;
	int		getGradeToSign() const;
	int		getGradeToExecute() const;
	string	getTarget() const;

	void	beSigned(const Bureaucrat bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
	

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();	
	};

	class FormNotSignedExecption : public std::exception {
	public:
		virtual const char *what() const throw();
	};

protected:
	void	checkExectionRequirement(Bureaucrat const & executor) const;

private:
	const string _name;
	const string _target;
	bool _is_signed;
	const int _grade_to_sign;
	const int _grade_to_execute;
};

ostream &operator<<(ostream& out, const AForm &form);

#endif // AFORM_HPP
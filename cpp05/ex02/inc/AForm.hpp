/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:53:49 by luma              #+#    #+#             */
/*   Updated: 2024/08/29 15:26:54 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <ostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	virtual ~AForm();

	AForm(const std::string name, const std::string target, const int grade_sign, const int grade_exec);

	// Getters
	
	std::string	getName() const;
	bool		isSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	std::string	getTarget() const;

	void			beSigned(const Bureaucrat bureaucrat);
	virtual void	execute(Bureaucrat const & executor) const = 0;
	

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

	class FormAlreadySignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

protected:
	void	checkExectionRequirement(Bureaucrat const & executor) const;

private:
	const std::string _name;
	const std::string _target;
	bool _is_signed;
	const int _grade_to_sign;
	const int _grade_to_execute;
};

std::ostream &operator<<(std::ostream& out, const AForm &form);

#endif // AFORM_HPP
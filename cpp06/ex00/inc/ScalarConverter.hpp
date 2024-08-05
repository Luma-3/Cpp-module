/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luma <luma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:56:16 by luma              #+#    #+#             */
/*   Updated: 2024/08/05 15:34:27 by luma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
public:

	static void convert(const std::string str);

	class IsImpossibleException : public std::exception {
	public:
		virtual const char *what() const throw();	
	};

	class NotDisplayableException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
	~ScalarConverter();
};

#endif // SCALARCONVERTER_HPP
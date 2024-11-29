/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:35:54 by jbrousse          #+#    #+#             */
/*   Updated: 2024/11/29 17:02:24 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <map>
#include <stdexcept>
#include <string>

#define DB_PATH "data.csv"

class BitcoinExchange
{
  private:
	std::string					   _file_path;
	std::ifstream				   _file;
	std::map< std::string, float > _db;

	void readData(std::ifstream &db_file);

	static void validateDate(const std::string &str);

  public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange();

	BitcoinExchange	  &operator=(const BitcoinExchange &rhs);
	static std::string trimSpace(const std::string &str);
	void			   findAndDisplay(const std::string &date, float value);

	/**
	 * Exception
	 */

	class FileOpenException : public std::runtime_error
	{
	  public:
		FileOpenException(const std::string	  &file_path,
						  const std::ifstream &file);

	  private:
		std::string getFileErrorMessage(const std::ifstream &file);
	};

	class InvalidFormatFile : public std::runtime_error
	{
	  public:
		InvalidFormatFile(const std::string &reason);
	};
};

#endif // BITCOINEXCHANGE_HPP

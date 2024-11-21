/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:55:14 by jbrousse          #+#    #+#             */
/*   Updated: 2024/08/21 12:42:24 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

using std::string;
using std::ifstream;
using std::ofstream;


int print_error()
{
	std::cout << "Error: Open file";
	return (1);
}

/**
 * @brief Replace Line occurences
*/
static string replace_line_ocs(string line, string s1, string s2) 
{
	if (line.empty())
		return ("\n");

	string result;
	
	size_t pos = 0;
	size_t old_pos = 0;
	while((pos = line.find(s1, pos)) != string::npos)
	{
		result.append(line, old_pos, pos - old_pos);
		result += s2;
		pos += s1.length();
		old_pos = pos;
	}
	result.append(line, old_pos, line.length() - old_pos);
	return (result + "\n");
}

int copy_file(string file_name, const char *s1, const char *s2)
{
	ifstream in_file(file_name.c_str());
	if (!in_file) return (print_error());

	string name_out = file_name += ".replace";
	ofstream out_file(name_out.c_str());
	if (!out_file) return (print_error());

	string line;
	while (std::getline(in_file, line))	{
		out_file << replace_line_ocs(line, string(s1), string(s2));
	}
	return (0);
}
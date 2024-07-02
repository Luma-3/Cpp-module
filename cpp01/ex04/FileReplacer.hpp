/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:43:12 by jbrousse          #+#    #+#             */
/*   Updated: 2024/07/02 11:27:32 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
#	define FILEREPLACER_HPP

#include <fstream>
#include <string>
#include <iostream>

int copy_file(std::string file_name, const char *s1, const char *s2);

#endif
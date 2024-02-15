/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:34:06 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/15 08:52:23 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <cctype>
# include <stdlib.h>
# include <cstdlib>
# include <limits>
# include <math.h>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& copy);
		ScalarConverter& operator=(ScalarConverter& copy);
		~ScalarConverter();
		
	public:
		static void convert(std::string str);
};

void convertDouble(std::string str);
void convertInt(std::string str);
void convertFloat(std::string str);
bool isChar(std::string str);
bool impossible(std::string str);

#endif
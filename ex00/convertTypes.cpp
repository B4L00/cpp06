/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertTypes.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:12:28 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/14 15:10:28 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void convertDouble(std::string str, bool notInt)
{
	std::stringstream	ss;
	double				d = 0.0;
	char				c = 0;
	int					i = 0;
	float				f = 0.0f;
	
	ss << str;
	ss >> d;

	c = static_cast<char>(d);
	i = static_cast<int>(d);
	
	if (notInt)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (c && isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
	}
	
	f = static_cast<float>(d);
	if (f == d)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
		
	if (ss.fail() && str[0] == '-')
		std::cout << "double: -inf" << std::endl;
	else if (ss.fail())
		std::cout << "double: inf" << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

void convertInt(std::string str)
{
	std::stringstream	ss;
	int					i = 0;
	char				c = 0;
	
	ss << str;
	ss >> i;
	
	if (ss.fail())
	{
		convertDouble(str, 1);
		return ;
	}

	c = static_cast<char>(i);
	if (c && isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	return ;
}

void convertFloat(std::string str)
{
	std::stringstream	ss;
	char				c = 0;
	int					i = 0;
	float				f = 0.0f;
	
	ss << str;
	ss >> f;
	if (ss.fail())
	{
		std::cout << "char: impossible" << std::endl;
		if (str[0] == '-')
		{
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		else
		{
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
		}
		return ;
	}
	
	c = static_cast<char>(f);
	i = static_cast<int>(f);

	if (i == floor(f))
	{
		if (c && isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
		
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	return ;
}

bool isChar(std::string str)
{
	char c = 0;
	
	if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
	{
		c = str[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return true;
	}
	return false;
}

bool impossible(std::string str)
{	
	if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return true;
	}
	
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}

	else if (str.length() == 0)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	return false;
}
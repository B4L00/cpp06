/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:34:09 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/01 14:35:47 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const& copy)
{
	(void) copy;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& copy)
{
	(void) copy;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string str)
{
	int 	i;
	double	d;
	char	c;
	float	f;

	

	if (str.find('f'))
		std::istringstream(str) >> f;
	else if (str.find('.'))
		std::istringstream(str) >> d;
	
	for (int j = 0; j < str.length(); j++)
	{
		
	}
	
	std::istringstream(str) >> i;
	
	c = 0;
	if (i > 31 && i < 127)
		c = char(i);
	
	if (c == 0)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float:" << f << std::endl;
	std::cout << "double: " << d << std::endl;
}
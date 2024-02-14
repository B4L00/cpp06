/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:34:09 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/14 14:04:21 by larmenou         ###   ########.fr       */
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
	unsigned int		j = 0;
	int 				cpt_dot = 0;
	int 				cpt_f = 0;
	int					cpt_sign = 0;
	std::stringstream	ss;
	
	if (isChar(str) || impossible(str))
		return ;

	while (str[j])
	{
		if (j != 0 && str[j] == 'f' && isdigit(str[j - 1]))
			cpt_f ++;
		else if (str[j] == '.' && j > 0 && j < str.length() - 1 && isdigit(str[j - 1]) && isdigit(str[j + 1]))
			cpt_dot ++;
		else if (j == 0 && ((str[j] == '-' || str[j] == '+') && str[j + 1] && isdigit(str[j + 1])))
			cpt_sign ++;
		else if (!isdigit(str[j]))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return ;
		}
		j++;
	}

	if (cpt_f == 0 && cpt_sign < 2 && cpt_dot == 0)
	{	
		convertInt(str);
		return ;
	}
	
	else if (cpt_f == 1 && cpt_sign < 2 && cpt_dot < 2)
	{
		convertFloat(str);
		return ;
	}
	
	else if (cpt_f == 0 && cpt_sign < 2 && cpt_dot < 2)
	{
		convertDouble(str, 0);
		return ;
	}
	
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}
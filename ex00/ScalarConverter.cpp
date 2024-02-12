/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:34:09 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/12 13:38:11 by larmenou         ###   ########.fr       */
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
	int 				i = 0;
	double				d = 0.0;
	char				c = 0;
	float				f = 0.0f;
	unsigned int		j = 0;
	int 				cpt_dot = 0;
	int 				cpt_f = 0;
	int					cpt_sign = 0;
	int					cpt_e = 0;
	std::stringstream	ss;
 
	if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
	{
		c = str[0];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return ;
	}
	
	if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << std::numeric_limits<int>::max() << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << std::numeric_limits<int>::min() << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}

	while (str[j])
	{
		if (j != 0 && str[j] == 'f' && isdigit(str[j - 1]))
			cpt_f ++;
		else if (str[j] == '.' && j > 0 && j < str.length() - 1 && isdigit(str[j - 1]) && isdigit(str[j + 1]))
			cpt_dot ++;
		else if (str[j] == 'e' && j > 0 && j < str.length() - 1 && isdigit(str[j - 1]) && (isdigit(str[j + 1]) || str[j + 1] == '-' || str[j + 1] == '+'))
			cpt_e ++;
		else if ((j == 0 || (j > 0 && str[j - 1] == 'e')) && ((str[j] == '-' || str[j] == '+') && str[j + 1] && isdigit(str[j + 1])))
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
	
	if (cpt_f == 1 && cpt_sign < 3 && cpt_dot < 2 && cpt_e < 2)
	{
		ss << str;
		ss >> f;

		if (ss.fail() || f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
		{
			std::cout << "char: Non displayable" << std::endl;
			if (str[0] == '-')
			{
				std::cout << "int: " << std::numeric_limits<int>::min() << std::endl;
       			std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			else
			{
				std::cout << "int: " << std::numeric_limits<int>::max() << std::endl;
       			std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;
			}
			return ;
		}
		
		c = static_cast<char>(f);

		if (c && c >= ' ' && c <= '~')
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
		return ;
	}

	else if (cpt_f == 0 && cpt_sign < 3 && cpt_dot == 0 && cpt_e < 2)
	{
		ss << str;
		ss >> i;
		c = static_cast<char>(i);
		if (c && c >= ' ' && c <= '~')
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
		return ;
	}
	
	else if (cpt_f == 0 && cpt_sign < 3 && cpt_dot < 3 && cpt_e < 2)
	{
		ss << str;
		ss >> d;

		if (ss.fail() || d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
		{
			std::cout << "char: Non displayable" << std::endl;
			if (str[0] == '-')
			{
				std::cout << "int: " << std::numeric_limits<int>::min() << std::endl;
       			std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			else
			{
				std::cout << "int: " << std::numeric_limits<int>::max() << std::endl;
       			std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;
			}
			return ;
		}

		c = static_cast<char>(d);
		if (c && c >= ' ' && c <= '~')
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
			
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		
		f = static_cast<float>(d);
		if (f < std::numeric_limits<float>::min())
			std::cout << "float: 0.0f" << std::endl;
		else if (f > std::numeric_limits<float>::max())
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: " << f << ".0f" << std::endl;
			
		std::cout << "double: " << d << ".0" << std::endl;
		return ;
	}
	
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
	
}
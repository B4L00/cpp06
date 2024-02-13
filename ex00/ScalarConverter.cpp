/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:34:09 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/13 14:41:06 by larmenou         ###   ########.fr       */
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

void convertDouble(std::string str)
{
	std::stringstream	ss;
	double				d = 0.0;
	char				c = 0;
	int					i = 0;
	float				f = 0.0f;
	
	ss << str;
	ss >> d;

	/* if (ss.fail())
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
	} */

	c = static_cast<char>(d);
	if (c && c >= ' ' && c <= '~')
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	i = static_cast<int>(d);
	if (i == d)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
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

void ScalarConverter::convert(std::string str)
{
	int 				i = 0;
	float				f = 0.0f;
	char				c = 0;
	unsigned int		j = 0;
	int 				cpt_dot = 0;
	int 				cpt_f = 0;
	int					cpt_sign = 0;
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
	
	else if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << std::numeric_limits<int>::max() << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	
	else if (str == "-inf" || str == "-inff")
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
		ss << str;
		ss >> i;
		
		if (ss.fail())
		{
			convertDouble(str);
			return ;
		}

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
	
	else if (cpt_f == 1 && cpt_sign < 2 && cpt_dot < 2)
	{
		ss << str;
		ss >> f;

		if (ss.fail())
		{
			std::cout << "char: Non displayable" << std::endl;
			if (str[0] == '-')
			{
				std::cout << "int: impossible" << std::endl;
       			std::cout << "float: -inff" << std::endl;
				std::cout << "double: " << static_cast<double>(f) << std::endl;
			}
			else
			{
				std::cout << "int: impossible" << std::endl;
       			std::cout << "float: +inff" << std::endl;
				std::cout << "double: " << static_cast<double>(f) << std::endl;
			}
			return ;
		}
		
		c = static_cast<char>(f);

		if (c && c >= ' ' && c <= '~')
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		i = static_cast<int>(f);
		if (i == f)
			std::cout << "int: " << i << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
			
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
		return ;
	}
	
	else if (cpt_f == 0 && cpt_sign < 2 && cpt_dot < 2)
	{
		convertDouble(str);
		return ;
	}
	
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
	
}
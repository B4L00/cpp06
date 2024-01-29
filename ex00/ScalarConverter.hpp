/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:34:06 by larmenou          #+#    #+#             */
/*   Updated: 2024/01/29 12:43:55 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		/* ScalarConverter(ScalarConverter const& copy); */
	public:
		/* ScalarConverter& operator=(ScalarConverter& copy); */
		~ScalarConverter();

		static void convert(std::string litteral);
};
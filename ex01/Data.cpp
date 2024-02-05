/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:20:27 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/05 10:52:40 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	_number = 0;
}

Data::Data(Data const& copy)
{
	this->_number = copy._number;
}

Data& Data::operator=(Data& copy)
{
	this->_number = copy._number;
	return (*this);
}

Data::~Data()
{}

int Data::getNumber() const
{
	return (_number);
}

void Data::setNumber(int n)
{
	_number = n;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:53:16 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/05 11:13:43 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data d;
	Data* c = new Data();
	uintptr_t u;
	int i = 42;

	std::cout << "Adresses comparison :" << std::endl;
	std::cout << "d: " << &d << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << std::endl;

	std::cout << "d.getNumber() should return 0: ";
	std::cout << d.getNumber() << std::endl;
	std::cout << "c->getNumber() should return 0: ";
	std::cout << c->getNumber() << std::endl;
	std::cout << std::endl;

	std::cout << "Serialization" << std::endl;
	u = Serializer::serialize(&d);
	d.setNumber(i);

	std::cout << "d.getNumber() should return " << i << ": ";
	std::cout << d.getNumber() << std::endl;
	std::cout << "c->getNumber() should return 0: ";
	std::cout << c->getNumber() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Deserialization" << std::endl;
	delete c;
	c = Serializer::deserialize(u);

	std::cout << "d.getNumber() should return " << i << ": ";
	std::cout << d.getNumber() << std::endl;
	std::cout << "c->getNumber() should return " << i << ": ";
	std::cout << c->getNumber() << std::endl;
	std::cout << std::endl;

	std::cout << "Adresses comparison :" << std::endl;
	std::cout << "d: " << &d << std::endl;
	std::cout << "c: " << c << std::endl;

	return (0);
}
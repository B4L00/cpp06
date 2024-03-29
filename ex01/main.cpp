/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:53:16 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/19 08:28:07 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data* data = new Data();
	Data *data_deserialized = new Data();
	uintptr_t raw;
	int i = 42;

	std::cout << "data adress: " << &data << std::endl;
	std::cout << "data: " << data << std::endl;
	std::cout << std::endl;

	std::cout << "setNumber(42)" << std::endl;
	data->setNumber(42);
	
	std::cout << "data->getNumber() should return " << i << ": ";
	std::cout << data->getNumber() << std::endl;
	std::cout << std::endl;

	std::cout << "data_deserialized->getNumber() should return 0: ";
	std::cout << data_deserialized->getNumber() << std::endl;
	std::cout << std::endl;

	std::cout << "Serialization" << std::endl;
	raw = Serializer::serialize(data);
	std::cout << "raw: " << raw << std::endl;

	std::cout << "data->getNumber() should return " << i << ": ";
	std::cout << data->getNumber() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Deserialization" << std::endl;
	data_deserialized = Serializer::deserialize(raw);

	std::cout << "data_deserialized->getNumber() should return " << i << ": ";
	std::cout << data_deserialized->getNumber() << std::endl;
	std::cout << std::endl;

	std::cout << "data_deserialized adress: " << &data_deserialized << std::endl;
	std::cout << "data_deserialized: " << data_deserialized << std::endl;

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:37:59 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/15 11:19:08 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{}

Base* Base::generate(void)
{
	int random;
	
	random = 1 + (rand() % 3);
	
	switch (random)
	{
		case 1:
			return (new A());
		case 2:
			return (new B());
		case 3:
			return (new C());
	}
	return (NULL);
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void Base::identify(Base& p)
{
	try
	{
		Base &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch(std::exception& e)
	{}
	
	try
	{
		Base &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B" << std::endl;
	}
	catch(std::exception& e)
	{}

	try
	{
		Base &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C" << std::endl;
	}
	catch(std::exception& e)
	{}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:02:55 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/15 11:10:02 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	srand((unsigned int)time(NULL));
	{
		Base b;
	
		Base *p;
		
		std::cout << "Generate random base" << std::endl;
		p = b.generate();
		b.identify(p);

		delete p;
	}

	{
		Base b2;
	
		std::cout << "Generate random base" << std::endl;
		Base &p = *b2.generate();
		b2.identify(p);
		
		delete &p;
	}
	
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:02:55 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/05 14:28:16 by larmenou         ###   ########.fr       */
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
		
		p = b.generate();
		b.identify(p);

		delete p;
	}

	{
		Base b2;
	
		Base &p = *b2.generate();
		b2.identify(p);
		
		delete &p;
	}
	
	return 0;
}
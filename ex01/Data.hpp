/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:13:51 by larmenou          #+#    #+#             */
/*   Updated: 2024/02/05 10:52:47 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	private:
		int _number;

	public:
		Data();
		Data(Data const& copy);
		Data& operator=(Data& copy);
		~Data();

		int getNumber() const;
		void setNumber(int n);
};

#endif
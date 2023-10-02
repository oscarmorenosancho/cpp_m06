/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:00:58 by omoreno-          #+#    #+#             */
/*   Updated: 2023/10/02 13:38:43 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"

int main(void)
{
	
	Base	*base;

	std::cout << "using identify pointer" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		base = Base::generate();
		Base::identify(base);
		delete base;
	}
	std::cout << "using identify reference" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		base = Base::generate();
		Base::identify(base);
		delete base;
	}
	return (0);
}

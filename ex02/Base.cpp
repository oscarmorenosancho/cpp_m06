/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:24:30 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/29 15:17:05 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base()
{}
Base* Base::generate(void)
{
	std::chrono::system_clock::time_point 	cur;
 	static long								*seed;

	cur = std::chrono::system_clock::now();
	seed = (long *)((char *)&cur + 
			sizeof(std::chrono::system_clock::time_point) - sizeof(long));
	srand(*seed);
	int selec = rand() % 3;
    if (selec == 0)
		return (new A);
    if (selec == 1)
		return (new B);
	return (new C);
}

void Base::identify(Base* p)
{
	std::string	t;
	int			count;

	t = typeid(*p).name();
	try
	{
		count = (std::to_string(stoi(t))).length();
	}
	catch(const std::exception& e)
	{
		count = 0;
	}
	std::cout << t.c_str() + count << std::endl;
}

void Base::identify(Base& p)
{
	std::string	t;
	int			count;

	t = typeid(p).name();
	try
	{
		count = (std::to_string(stoi(t))).length();
	}
	catch(const std::exception& e)
	{
		count = 0;
	}
	std::cout << t.c_str() + count << std::endl;
}
